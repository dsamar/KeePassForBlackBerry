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
                lockoutTimerSetting.text = dbs.getValueFor("lockoutTimerSetting", "30");
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
            masterPassword.requestFocus();
        }
    }
    // A reference to to the Page for presenting the page is kept while showing it
    // in order to update its data when deleting and editing the password.
    property variant passwordPage

    onPopTransitionEnded: {
        // The only occurrence of a pop transition that ends is when the Page
        // with the text in a bubble is pushed by back navigation, this Page
        // is created each time the a new qoute is selected in the list so
        // in order to avoid memory leaks it is destroyed here.
        if (passwordPage == page) {
            page.destroy();
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

            // passwordPage.deleteQuote.connect(quotesListPage.deleteSelectedQuote);
            // passwordPage.updateQuote.connect(quotesListPage.updateSelectedQuote);
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
                    if (true == searchBox.visible)
                    {
                        searchBox.visible = false;
                        searchTextField.requestFocus();
                        dbs.populateGroupDataModel();
                        searchTextField.setText(undefined);
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
    } // end of Page
    attachedObjects: [
        ComponentDefinition {
            id: appCover
            source: "AppCover.qml"
        },
        Sheet {
            id: lockScreenSheet
            peekEnabled: false
            content: Page {
                id: openDbPage
                content: Container {
                    layout: DockLayout {

                    }
                    Container {
                        leftPadding: 40.0
                        topPadding: 40.0
                        rightPadding: 40.0
                        layout: StackLayout {

                        }
                        verticalAlignment: VerticalAlignment.Center
                        horizontalAlignment: HorizontalAlignment.Center
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight

                            }
                            verticalAlignment: VerticalAlignment.Center
                            horizontalAlignment: HorizontalAlignment.Center
                            bottomMargin: 40.0
                            topMargin: 40.0
                            leftMargin: 40.0
                            rightMargin: 40.0
                            ImageView {
	                            imageSource: "asset:///images/icon.png"
	                            verticalAlignment: VerticalAlignment.Center
	                            horizontalAlignment: HorizontalAlignment.Left
                            }                 
                            Label {
                                text: qsTr("KeePass for BlackBerry")
                                textStyle.fontSize: FontSize.Large
                                textStyle.fontWeight: FontWeight.W300
                                verticalAlignment: VerticalAlignment.Center
                                horizontalAlignment: HorizontalAlignment.Center

                            }
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight

                            }
                            TextField { // DATABASE FILE PATH
                                id: kdbPath
                                verticalAlignment: VerticalAlignment.Center
                                hintText: qsTr("Database Path")
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 4.0
                                }
                                text: dbs.getValueFor("kdbPath", "")
                                onTextChanged: {
                                    dbs.saveValueFor("kdbPath", kdbPath.text)
                                }
                            }
                            Button { // DATABASE FILE PICKER
                                imageSource: "asset:///images/database.png"
                                verticalAlignment: VerticalAlignment.Center
                                onClicked: {
                                    kdbFilePicker.open()
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                            }
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight

                            }
                            TextField { // KEY FILE PATH
                                id: kdbKeyPath
                                verticalAlignment: VerticalAlignment.Center
                                hintText: qsTr("Key File Path")
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 4.0
                                }
                                text: dbs.getValueFor("kdbKeyPath", "")
                                onTextChanged: {
                                    dbs.saveValueFor("kdbKeyPath", kdbKeyPath.text)
                                }
                            }
                            Button { // KEY FILE PICKER
                                imageSource: "asset:///images/key.png"
                                verticalAlignment: VerticalAlignment.Center
                                onClicked: {
                                    kdbKeyFilePicker.open()
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                            }
                        }
                        TextField { // PASSWORD FIELD
                            id: masterPassword
                            verticalAlignment: VerticalAlignment.Center
                            textFormat: TextFormat.Plain
                            inputMode: TextFieldInputMode.Password
                            hintText: qsTr("Password")
                        }
                        Button { // OPEN DATABASE BUTTON
                            id: kdbOpenButton
                            shortcuts: Shortcut {
                                key: "Return"
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
                                dbs.unlock(kdbPath.text, masterPassword.text, kdbKeyPath.text, true)
                            }
                            function onDbsUnlock(val) {
                                if ("Success" == val) {
                                    kdbProgressDialog.cancel();
                                    lockScreenSheet.close();
                                    dbs.populateGroupDataModel();
                                    masterPassword.setText(undefined);
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
                        Button { // TRIAL DATABASE BUTTON
                            id: kdbTrialOpenButton
                            verticalAlignment: VerticalAlignment.Bottom
                            text: qsTr("Demo Database")
                            visible: true
                            onClicked: {
                                kdbProgressDialog.confirmButton.label = "Cancel";
                                kdbProgressDialog.show();
                                dbs.valueChanged.connect(kdbOpenButton.onDbsUnlock)
                                dbs.unlockTrial();
                            }
                            horizontalAlignment: HorizontalAlignment.Center
                            function onDbsUnlock(val) {
                                if ("Success" == val) {
                                    kdbProgressDialog.cancel();
                                    lockScreenSheet.close();
                                    dbs.populateGroupDataModel();
                                    masterPassword.setText(undefined);
                                } else {
                                    kdbErrorDialog.body = val;
                                    kdbErrorDialog.cancelButton.label = undefined;
                                    kdbErrorDialog.show();
                                    kdbProgressDialog.cancel();
                                }
                            }
                        }

                    } // end of Container
                }                
                attachedObjects: [
                    FilePicker {
                        id: kdbFilePicker
                        type: FileType.Other
                        title: qsTr("Select KeePass database file.")
                        directories: [ "/accounts/1000/shared/" ]
                        onFileSelected: {
                            console.log("FileSelected signal received : " + selectedFiles);
                            var nice_path = selectedFiles[0].slice(15, selectedFiles[0].length);
                            kdbPath.setText(nice_path);
                        }
                    },
                    FilePicker {
                        id: kdbKeyFilePicker
                        type: FileType.Other
                        title: qsTr("Select a key file.")
                        directories: [ "/accounts/1000/shared/" ]
                        onFileSelected: {
                            console.log("FileSelected signal received : " + selectedFiles);
                            var nice_path = selectedFiles[0].slice(15, selectedFiles[0].length);
                            kdbKeyPath.setText(nice_path);
                        }
                    },
                    SystemProgressDialog {
                        id: kdbProgressDialog
                        title: "Loading"
                    },
                    SystemDialog {
                        id: kdbErrorDialog
                        title: "Error"
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
                                    dbs.saveValueFor("lockoutTimerSetting", lockoutTimerSetting.text)
                                    settingsSheet.close(); 
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
                    // Timeout Period
                    Label {
                        text: qsTr("Lockout Timer (Seconds):")
                        verticalAlignment: VerticalAlignment.Center
                    }
                    TextField {
                        id: lockoutTimerSetting
                        text: dbs.getValueFor("lockoutTimerSetting", "30")
                        horizontalAlignment: HorizontalAlignment.Left
                        verticalAlignment: VerticalAlignment.Center
                        inputMode: TextFieldInputMode.NumbersAndPunctuation
                    }
                }
                
            }
        }
    ]
    
    
    function lockDatabase()
    {
    	dbs.setLock(true);
    }
} // end of navigation