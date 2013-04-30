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

#include <bb/cascades/Application>
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
    new DBControlService(&app);

    // we complete the transaction started in the app constructor and start the client event loop here
    return Application::exec();
    // when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
}

