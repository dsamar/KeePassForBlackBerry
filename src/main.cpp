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

#include <bb/cascades/Application>
#include <bb/platform/HomeScreen>
#include <QLocale>
#include <QTranslator>
#include <QObject>
#include <bb/system/InvokeManager.hpp>
#include "lib/SecString.h"
#include "crypto/yarrow.h"

// include JS Debugger / CS Profiler enabler
// this feature is enabled by default in the debug build only
#include <Qt/qdeclarativedebug.h>
#include "DBControlService.h"

using namespace bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv)
{
    // this is where the server is started etc
    Application app(argc, argv);
    bb::platform::HomeScreen homeScreen;

	// Initialization Stuff
    initYarrow();
	SecString::generateSessionKey();

    // localization support
    QTranslator translator;
    QString locale_string = QLocale().name();
    QString filename = QString( "KeePassBB_%1" ).arg( locale_string );
    if (translator.load(filename, "app/native/qm")) {
        app.installTranslator( &translator );
    }

//    bb::system::InvokeManager invokeManager;
//    QObject::connect(invokeManager,
//        SIGNAL(invoked(const bb::system::InvokeRequest&),
//        &myApp, SLOT(onInvoke(const bb::system::InvokeRequest&));
//  
//    switch(invokeManager.startupMode()) {
//    case ApplicationStartupMode::LaunchApplication:
//        // An application can initialize if it
//        // was launched from the home screen
//        break;
//    case ApplicationStartupMode::InvokeApplication:
//        // If the application is invoked,
//        // it must wait until it receives an invoked(..) signal
//        // so that it can determine the UI that it needs to initialize
//        break;
//    default:
//        // What app is it and how did it get here?
//        break;
//    }

    // create the application pane object to init UI etc.
    new DBControlService(&app, &homeScreen);

    // we complete the transaction started in the app constructor and start the client event loop here
    return Application::exec();
    // when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
}

