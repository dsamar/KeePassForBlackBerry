/***************************************************************************
 *   Copyright (C) 2013 by Dan Samargiu                                    *
 *   samargiudan@gmail.com                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/

import bb.cascades 1.0
import bb.system 1.0

Page {
	id: passwordPage
	
	// Data property, this is updated when navigation occurs, has three entries.
	property variant passwordData: {
	    "title": "something",
	    "username": "Some Guy",
	    "password": "test123",
	    "url": "http://somewebsite.com",
	    "comment": "some comment"
	}
	
	// Signals for handling data updates triggered from the  Page.
	signal back()
	
	titleBar: TitleBar {
    	title: passwordData.title
    }

    Container {
        layout: StackLayout {
        }

        leftPadding: 40.0
        rightPadding: 40.0
        topPadding: 40.0
        verticalAlignment: VerticalAlignment.Top
        horizontalAlignment: HorizontalAlignment.Left
        Container { // URL FIELD
            layout: DockLayout {

            }
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Fill
            Container {
                layout: StackLayout {

                }
                verticalAlignment: VerticalAlignment.Top
                Label {
                    text: qsTr("URL:")
                    textStyle.color: Color.LightGray
                }
                Label {
                    text: passwordData.url
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Bold
                    textFormat: TextFormat.Html
                    verticalAlignment: VerticalAlignment.Bottom
                }
            }
            ImageButton {
                id: openUrl
                onClicked: {
                    // Open Webpage
                    passwordData.launchBrowser();
                }
                
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Right
                defaultImageSource: "asset:///images/open_browser_blue.png"
                pressedImageSource: "asset:///images/open_browser_blue.png"
                disabledImageSource: "asset:///images/open_browser_blue.png"
            }
        }
        
        Divider {
        }
        Container { // USERNAME FIELD
            layout: DockLayout {

            }
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Fill
            Container {
                layout: StackLayout {

                }
                verticalAlignment: VerticalAlignment.Top
                Label {
		            text: qsTr("User name:")
		            textStyle.color: Color.LightGray
		        }
		        Label {
		            text: passwordData.username
		            textStyle.color: Color.White
		            textStyle.fontWeight: FontWeight.Bold
	                verticalAlignment: VerticalAlignment.Bottom
	            }
             }
        }
        Divider {}
        Container { // PASSWORD FIELD
            layout: DockLayout {

            }
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Fill
            Container {
                layout: StackLayout {

                }
                verticalAlignment: VerticalAlignment.Top
                Label {
	                text: qsTr("Password:")
	                textStyle.color: Color.LightGray
	            }
	            Label {
	                id: passwordField
	                text: qsTr("******")
	                textStyle.color: Color.White
	                textStyle.fontWeight: FontWeight.Bold
	                verticalAlignment: VerticalAlignment.Bottom
	                horizontalAlignment: HorizontalAlignment.Left
	            }
            }
            ImageToggleButton {
                id: passwordUnlock
                checked: false
                imageSourcePressedChecked: "asset:///images/icon_212.png"
                imageSourcePressedUnchecked: "asset:///images/icon_194.png"
                onCheckedChanged: {
                    if (checked)
                    {
                        passwordField.setText(passwordData.passwordUnlocked);
                    } else {
                        passwordField.setText(qsTr("******"));
                    }
                }
                verticalAlignment: VerticalAlignment.Center
                imageSourceDefault: "asset:///images/icon_194.png"
                imageSourceDisabledUnchecked: "asset:///images/icon_194.png"
                imageSourceDisabledChecked: "asset:///images/icon_212.png"
                imageSourceChecked: "asset:///images/icon_212.png"
                horizontalAlignment: HorizontalAlignment.Right
            }
        }
        
        Divider {
        }
        Container { // NOTES FIELD
            layout: DockLayout {

            }
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Fill
            Container {
                layout: StackLayout {

                }
                verticalAlignment: VerticalAlignment.Top
                Label {
		            text: qsTr("Notes:")
		            textStyle.color: Color.LightGray
		            verticalAlignment: VerticalAlignment.Top
	            }
		        TextArea {
		            text: passwordData.comment
		            textStyle.color: Color.White
		            textStyle.fontWeight: FontWeight.Bold
		            verticalAlignment: VerticalAlignment.Bottom
                    maximumLength: 1000000
                    editable: false
                    backgroundVisible: false
                }
          	}
	    }

    } // Container

    paneProperties: NavigationPaneProperties {
        backButton: ActionItem {
            title: "Names"
            onTriggered: {
                // Bubble.editMode = false;
                passwordPage.back();
            }
        }
    }

    actions: [
        ActionItem {
            title: "Copy Password"
            imageSource: "asset:///images/password_copy.png"
            ActionBar.placement: ActionBarPlacement.OnBar

            onTriggered: {
                passwordData.copyPasswordToClipboard();
                copyClipboardTost.body = qsTr("Password copied to clipboard.");
                copyClipboardTost.show();
            }
        },
        ActionItem {
            title: "Copy Username"
            imageSource: "asset:///images/username_copy.png"
            ActionBar.placement: ActionBarPlacement.OnBar

            onTriggered: {
                passwordData.copyUsernameToClipboard();
                copyClipboardTost.body = qsTr("Username copied to clipboard.");
                copyClipboardTost.show();
            }
        }
    ]
    
    attachedObjects: [
        SystemToast {
            id: copyClipboardTost
            body: qsTr("Password copied to clipboard.")
        }
    ]
}// Password Page
