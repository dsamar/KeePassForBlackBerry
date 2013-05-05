/***************************************************************************
   Copyright 2013 Dan Samargiu

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
***************************************************************************/

import bb.cascades 1.0
import bb.cascades.pickers 1.0
import bb.system 1.0

NavigationPane {
	id: nav

    // Add the application menu using a MenuDefinition
    Menu.definition: MenuDefinition {

//		helpAction: HelpActionItem {
//            onTriggered: {
//            	helpSheet.open();
//            }
//        }
		
		settingsAction: SettingsActionItem {
		    onTriggered: {
                lockoutTimerSetting.setSelectedIndex(dbs.getDatabaseSettingFor("lockoutTimerSetting", "0"));
                settingsSheet.open();
            }
		}
		
        // Specify the actions that should be included in the menu
        actions: [
            ActionItem {
                id: kdbLockButton
                title: qsTr("Lock")
                imageSource: "asset:///images/ic_lock.png"
                onTriggered: {
                    lockDatabase();
                }
            }
        ] // end of actions list
    } // end of MenuDefinition

    function onLockChanged(val) {
        if (val == true) {
            if ( !groupDataModel.isEmpty() )
            {
                nav.pop();
                groupDataModel.clear();
            }
            lockScreenSheet.open();
        }
    }
    // A reference to to the Page for presenting the page is kept while showing it
    // in order to update its data when deleting and editing the password.
    property variant passwordPage

    onPopTransitionEnded: {
        if (passwordPage == page) {
            page.destroy();
            
            if(searchBox.visible) // if we had the search box up, resume focus to it.
            {
                searchTextField.requestFocus();
            }
        }
    }
    Page {
        property variant selectedData

        // Custom signals used to communicate navigation
        signal showPasswordPage()
        signal listEmpty()

        onShowPasswordPage: {
            // Create the content page and push it on top to drill down to it.
            passwordPage = passwordPageDefinition.createObject();
            passwordPage.passwordData = selectedData;
            nav.push(passwordPage);
            passwordPage.back.connect(nav.pop);
        }

        onSelectedDataChanged: {
            if (passwordPage != undefined) {
                passwordPage.passwordData = selectedData;
            }
        }

        onListEmpty: {
            if (nav.top == passwordPage) {
                nav.pop();
            }
        }

        id: passwordListPage
        content: Container {
            attachedObjects: [
                // Add the data model as an attached object. Make sure
                // to specify a value for the objectName property,
                // which is used to access the model from C++.
                GroupDataModel {
                    id: groupDataModel
                    objectName: "groupDataModel"
                    sortingKeys: [ "title" ]
                }
            ]

			Container {
       			id: searchBox
       			visible: false
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight

                }
                TextField {
                    id: searchTextField
                    focusPolicy: FocusPolicy.KeyAndTouch
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 4.0

                    }
                	hintText: qsTr("Search")
                	onTextChanging: {
                        dbs.searchText(searchTextField.text);
                    }
                }
                Button {
                    horizontalAlignment: HorizontalAlignment.Right
                    text: qsTr("Cancel")
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0

                    }
                    onClicked: {
                        searchBox.visible = false;
                        dbs.populateGroupDataModel();
                        searchTextField.setText(undefined);
                    }
                }
            }
            ListView {
                id: listView

                // Associate the GroupDataModel from the attached objects
                // list with this ListView
                dataModel: groupDataModel

                listItemComponents: [
                    // Use a ListItemComponent to define the appearance of
                    // list items (that is, those with a type of "listItem")
                    ListItemComponent {
                        type: "listItem"

                        // Each list item is represented by a StandardListItem
                        // whose text fields are populated with data from the
                        // item
                        StandardListItem {
                            title: ListItemData.title
                            imageSource: "asset:///images/entry_icons/_" + ListItemData.image + ".png"
                        }
                    }
                ]

                onTriggered: {
                    // Update the data that will be shown in the password Page.
                    passwordListPage.selectedData = dataModel.data(indexPath);
                    passwordListPage.showPasswordPage();
                }

                // Override the itemType() function to return the proper type
                // for each item in the list. Because a GroupDataModel has only
                // two levels, use the index path to determine whether the item
                // is a header item or a list item.
                function itemType(data, indexPath) {
                    if (indexPath.length == 1) {
                        // If the index path contains a single integer, the item
                        // is a "header" type item
                        return "header";
                    } else {
                        // If the index path contains more than one integer, the
                        // item is a "listItem" type item
                        return "listItem";
                    }
                }
            }
        } // end of Container
        actions: [
            ActionItem {
                id: kdbSearch
                title: qsTr("Search")
                imageSource: "asset:///images/entry_icons/_40.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                onTriggered: {
                    if (searchBox.visible)
                    {
                        searchBox.visible = false;
                        dbs.populateGroupDataModel();
                        searchTextField.setText(undefined);
                        listView.requestFocus();
                    } else {
                        searchBox.visible = true;
                        searchTextField.requestFocus();
                    }
                }
            }
        ]
        onCreationCompleted: {
            dbs.lockChanged.connect(nav.onLockChanged)
            if ( !dbs.isLocked )
            {
                lockDatabase()
            }
            lockScreenSheet.open();
            Application.cover = appCover.createObject();
        }
        attachedObjects: [
            ComponentDefinition {
                // Definition used for creating a Content Page to which the
                // user can drill down to read the password.
                id: passwordPageDefinition
                source: "PasswordPage.qml"
            }
        ]
        keyListeners: [
            KeyListener {
                onKeyPressed: {
                    if (!searchBox.visible)
                    {
                        var char_pressed = event.key;
                        console.log("KEY CODE --" + char_pressed);
                        if (dbs.charcodeIsLetter(char_pressed) && 
                        	undefined != char_pressed && 
                        	233 != char_pressed &&
                        	225 != char_pressed &&
                        	32 != char_pressed) // Alt and Shift and Space keys should not trigger search.
                        {
                            // check if key is a letter or number
                            searchBox.visible = true;
                            searchTextField.requestFocus();
                            searchTextField.setText(dbs.charcodeToQString(char_pressed));
                        }
                    }
                    else {
                        var char_pressed = event.key;
                        if (8 == char_pressed) // Backspace hit when search is visible and empty closes search
                        {
                            if ("" == searchTextField.text || undefined == searchTextField.text) {
                                searchBox.visible = false;
                                dbs.populateGroupDataModel();
                                searchTextField.setText(undefined);
                                listView.requestFocus();
                            }
                        }
                    }
                }
            }
        ]
    } // end of Page
    attachedObjects: [
        ComponentDefinition {
            id: appCover
            source: "AppCover.qml"
        },
        Sheet {            
            id: lockScreenSheet
            onOpened: {
                masterPassword.requestFocus();
            }
            peekEnabled: false
            content: Page {
                id: openDbPage
                titleBar: TitleBar {
                    kind: TitleBarKind.FreeForm
                    kindProperties: FreeFormTitleBarKindProperties {
                        content: Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight

                            }
                            verticalAlignment: VerticalAlignment.Center
                            horizontalAlignment: HorizontalAlignment.Left
                            bottomMargin: 40.0
                            topMargin: 40.0
                            leftMargin: 40.0
                            rightMargin: 40.0
                            ImageView {
                                imageSource: "asset:///images/icon.png"
                                verticalAlignment: VerticalAlignment.Center
                                horizontalAlignment: HorizontalAlignment.Left
                                scaleX: 0.6
                                scaleY: 0.7
                            }
                            Label {
                                text: qsTr("KeePass for BlackBerry")
                                textStyle.fontSize: FontSize.Large
                                textStyle.fontWeight: FontWeight.W400
                                verticalAlignment: VerticalAlignment.Center
                                horizontalAlignment: HorizontalAlignment.Left

                            }
                        }
                    }
                }
                content: Container {
                    layout: DockLayout {

                    }
                    Container {
                        leftPadding: 20.0
                        topPadding: 20.0
                        rightPadding: 20.0
                        layout: StackLayout {

                        }
                        verticalAlignment: VerticalAlignment.Center
                        horizontalAlignment: HorizontalAlignment.Center
                        DropDown {
                            id: kdbPath
                            title: qsTr("Database")
                            enabled: true
                            Option {
                                id: demoDatabaseOption
                                imageSource: "asset:///images/entry_icons/_63.png"
                                text: qsTr("Demo Database")
                                value: qsTr("DEMO")
                                onSelectedChanged: {
                                    if (selected == true) {
                                        // Demo database
                                        kdbKeyPath.visible = false;
                                        kdbKeyPath.enabled = false;
                                        masterPassword.visible = false;
                                        masterPassword.enabled = false;
                                        masterPassword.setText(undefined);
                                        dbs.saveGlobalSettingFor("kdbPath", "DEMO");
                                    } else {
                                        kdbKeyPath.visible = true;
                                        kdbKeyPath.enabled = true;
                                        masterPassword.visible = true;
                                        masterPassword.enabled = true;
                                    }
                                }
                            }

                            Option {
                                imageSource: "asset:///images/folder_open.png"
                                text: qsTr("Select a file...")
                                onSelectedChanged: {
                                    if (selected == true) {
                                        kdbFilePicker.open()
                                    }
                                }
                            }
                        }
                        DropDown {
                            id: kdbKeyPath
                            title: qsTr("Key File")
                            enabled: true
                            Option {
                                id: noKeyOption
                                text: qsTr("None");
                                value: "default"
                                imageSource: "asset:///images/entry_icons/_45.png"
                                onSelectedChanged: {
                                    if (selected == true)
                                    {
                                        dbs.saveGlobalSettingFor("kdbKeyPath", noKeyOption.value);
                                    }
                                }
                            }
                            Option {
                                imageSource: "asset:///images/folder_open.png"
                                text: qsTr("Select a file...")
                                onSelectedChanged: {
                                    if (selected == true) {
                                        kdbKeyFilePicker.open()
                                    }
                                }
                            }
                        }
                        TextField { // PASSWORD FIELD
                            id: masterPassword
                            verticalAlignment: VerticalAlignment.Center
                            textFormat: TextFormat.Plain
                            inputMode: TextFieldInputMode.Password
                            hintText: qsTr("Password")
                            shortcuts: Shortcut {
                                key: qsTr("Enter")
                                onTriggered: {
                                    kdbOpenButton.clicked();
                                }
                            }
                        }
                        Button { // OPEN DATABASE BUTTON
                            id: kdbOpenButton
                            focusPolicy: FocusPolicy.KeyAndTouch
                            shortcuts: Shortcut {
                                key: qsTr("Enter")
                                onTriggered: {
                                    kdbOpenButton.clicked();
                                }
                            }
                            verticalAlignment: VerticalAlignment.Center
                            text: qsTr("Open")
                            onClicked: {
                                kdbProgressDialog.confirmButton.label = "Cancel";
                                kdbProgressDialog.show();
                                dbs.valueChanged.connect(kdbOpenButton.onDbsUnlock)

                                // Check if demo database is selected.
                                if (kdbPath.selectedValue == qsTr("DEMO")) {
                                    dbs.unlockTrial();
                                } else {
                                    dbs.unlock(kdbPath.selectedValue, masterPassword.text, kdbKeyPath.selectedValue, true)
                                }
                            }
                            function onDbsUnlock(val) {
                                if ("Success" == val) {
                                    unlockDatabase();
                                } else {
                                    kdbErrorDialog.body = val;
                                    kdbErrorDialog.cancelButton.label = undefined;
                                    kdbErrorDialog.show();
                                    kdbProgressDialog.cancel();
                                }
                            }
                            horizontalAlignment: HorizontalAlignment.Center
                            visible: true
                        }
                    } // end of Container
                }                
                attachedObjects: [
                    FilePicker {
                        id: kdbFilePicker
                        type: FileType.Other
                        title: qsTr("Select KeePass database file.")
                        directories: [ "/accounts/1000/shared/" ]
                        onCanceled: {
                            kdbPath.setSelectedIndex(-1);
                        }
                        onFileSelected: {
                            var nice_path = selectedFiles[0].slice(15, selectedFiles[0].length);
                            var newOption = selectedDatabaseOptionComponent.createObject();
                            kdbPath.add(newOption);
                            newOption.setText(nice_path);
                            newOption.setValue(nice_path);
                            kdbPath.setSelectedOption(newOption);

                            // Save in global settings.
                            dbs.saveGlobalSettingFor("kdbPath", nice_path);
                        }
                    },
                    FilePicker {
                        id: kdbKeyFilePicker
                        type: FileType.Other
                        title: qsTr("Select a key file.")
                        directories: [ "/accounts/1000/shared/" ]
                        onCanceled: {
                            kdbKeyPath.setSelectedOption(noKeyOption);
                        }
                        onFileSelected: {
                            var nice_path = selectedFiles[0].slice(15, selectedFiles[0].length);
                            var newOption = selectedKeyFileOptionComponent.createObject();
                            kdbKeyPath.add(newOption);
                            newOption.setText(nice_path);
                            newOption.setValue(nice_path);
                            kdbKeyPath.setSelectedOption(newOption)
                            
                            // Save in global settings.
                            dbs.saveGlobalSettingFor("kdbKeyPath", nice_path);
                        }
                    },
                    SystemProgressDialog {
                        id: kdbProgressDialog
                        title: "Loading"
                    },
                    SystemDialog {
                        id: kdbErrorDialog
                        title: "Error"
                    },
                    ComponentDefinition {
                        id: selectedDatabaseOptionComponent
                        content: Option {
                            id: selectedDatabaseOption
                            onSelectedChanged: {
                                if (selected == true) {
                                    dbs.saveGlobalSettingFor("kdbPath", selectedDatabaseOption.value);
                                }
                            }
                            imageSource: "asset:///images/database.png"
                        }
                    },
                    ComponentDefinition {
                        id: selectedKeyFileOptionComponent
                        content: Option {
                            id: selectedKeyFileOption
                            onSelectedChanged: {
                                if (selected == true) {
                                    dbs.saveGlobalSettingFor("kdbKeyPath", selectedKeyFileOption.value);
                                }
                            }
                            imageSource: "asset:///images/key.png"
                        }
                    }
                ] // end of attachedObjects list
            } // End of Page
        },
        Sheet {
            id: settingsSheet
            content: Page {
                titleBar: TitleBar {
                    kind: TitleBarKind.FreeForm
                    kindProperties: FreeFormTitleBarKindProperties {
                        content: Container {
                            layout: DockLayout {

                            }
                            leftPadding: 15.0
                            rightPadding: 10.0
                            topPadding: 10.0
                            bottomPadding: 10.0
                            Label {
                                text: qsTr("Settings")
                                textFormat: TextFormat.Auto
                                verticalAlignment: VerticalAlignment.Center
                                textStyle.fontSize: FontSize.Large
                                textStyle.fontWeight: FontWeight.W400
                            }
                            Button {
                        	    text: qsTr("Done")
                        	    onClicked: {
                                    settingsSheet.close(); 
                                    if (searchBox.visible)
                                    {
                                        searchTextField.requestFocus();
                                    }
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                            }
                        }
                    }    
                }
                
                Container {
                    layout: StackLayout {

                    }
                    DropDown {
                        id: lockoutTimerSetting
                        selectedIndex: dbs.getDatabaseSettingFor("lockoutTimerSetting", "0")
                        title: qsTr("Lockout Timer")
                        onSelectedValueChanged: {
                            dbs.saveDatabaseSettingFor("lockoutTimerSetting", lockoutTimerSetting.selectedIndex)
                        }
                    }
                }
                //
                // Per bug BBTEN-302: I need to specify a new ComponentDefinition in the attachedObjects section
                //                    In order to add options to a DropDown
                //                    http://boredwookie.net/index.php/blog/blackberry-10-cascades-create-a-custom-control-dropdownlist/
                //
                attachedObjects: [
                    ComponentDefinition {
                        id: option
                        Option {
                        }
                    }
                ]
                
                onCreationCompleted: {
                    initializeSettings();
                    restoreLockScreenSelections();
                }
            }
        }
    ]
    
    function restoreLockScreenSelections()
    {
        var dbPath = dbs.getGlobalSettingFor("kdbPath", "default");
        if (dbPath == "DEMO") {
            kdbPath.setSelectedOption(demoDatabaseOption);
            return;
        }

        if (dbPath != "default")
        {
            var dbOption = selectedDatabaseOptionComponent.createObject();
            kdbPath.add(dbOption);
            dbOption.setText(dbPath);
            dbOption.setValue(dbPath);
            kdbPath.setSelectedOption(dbOption);
        }
        
        var keyPath = dbs.getGlobalSettingFor("kdbKeyPath", "default");
        if (keyPath != "default")
        {
            var keyOption = selectedKeyFileOptionComponent.createObject();
            kdbKeyPath.add(keyOption);
            keyOption.setText(keyPath);
            keyOption.setValue(keyPath);
            kdbKeyPath.setSelectedOption(keyOption)
        } else {
            kdbKeyPath.setSelectedOption(noKeyOption);
        }
    }
    
    function unlockDatabase()
    {
        kdbProgressDialog.cancel();
        lockScreenSheet.close();
        dbs.populateGroupDataModel();
        masterPassword.setText(undefined);
        loadDatabaseSettings();
    }
    
    function lockDatabase()
    {
        searchBox.visible = false;
        searchTextField.setText(undefined);
        dbs.setLock(true);
    }
    
    function initializeSettings() {
        var xmlContents = XML.LoadXML("lockoutTimerDropDown.xml", "lockoutTimerOption", ["text", "value"]); // Call the C++ Method to load the XML data. 3 arguments: XML File, Row name, attribute name

        // Clear the contents of the DropDown
        lockoutTimerSetting.removeAll();

        // Add the options from the XML to the DropDown
        for (var x = 0; x < xmlContents.length; x ++) {
            var opt = option.createObject(); //
            opt.text = xmlContents[x].text; // Needs to be an 'Option' before the DropDown will accept it

            lockoutTimerSetting.add(opt);
        }
    }
    
    function loadDatabaseSettings() {
        lockoutTimerSetting.setSelectedIndex(dbs.getDatabaseSettingFor("lockoutTimerSetting", "0"))
    }
} // end of navigation