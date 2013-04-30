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

#ifndef DBCONTROLSERVICE_H_
#define DBCONTROLSERVICE_H_

#include <QObject>
#include <QString>
#include <QSettings>
#include <qstring.h>
#include "KPBBEntryHandle.h"
#include "KPBBGroupHandle.h"
#include "Database.h"
#include "Kdb3Database.h"
#include <bb/cascades/Application>
#include <bb/cascades/Container>
#include <bb/cascades/GroupDataModel>
#include <bb/cascades/CustomControl>
#include <bb/cascades/Page>
#include <bb/cascades/NavigationPane>

using namespace bb::cascades;

namespace bb { namespace cascades { class Application; }}

class KPBBGroupHandle;
class KPBBEntryHandle;
class DBControlService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool isLocked READ isLocked WRITE setLock NOTIFY lockChanged)


public:
    DBControlService(bb::cascades::Application *app);
	virtual ~DBControlService();

	Q_INVOKABLE void unlockTrial();
	Q_INVOKABLE void unlock(
			QString filePath,
			QString password,
			QString keyFile,
			bool readOnly);

	Q_INVOKABLE void populateGroupDataModel();
	Q_INVOKABLE void searchText(const QString& searchString);

	/**
	 * This Invokable function gets a value from the QSettings,
	 * if that value does not exist in the QSettings database, the default value is returned.
	 *
	 * @param objectName Index path to the item
	 * @param defaultValue Used to create the data in the database when adding
	 * @return If the objectName exists, the value of the QSettings object is returned.
	 *         If the objectName doesn't exist, the default value is returned.
	 */
	Q_INVOKABLE
	QString getValueFor(const QString &objectName, const QString &defaultValue);

	/**
	 * This function sets a value in the QSettings database. This function should to be called
	 * when a data value has been updated from QML
	 *
	 * @param objectName Index path to the item
	 * @param inputValue new value to the QSettings database
	 */
	Q_INVOKABLE
	void saveValueFor(const QString &objectName, const QString &inputValue);

	QString value();
	bool isLocked();
	void setValue(QString s);
	Q_SLOT void setLock(bool b);
	Q_SLOT void setLockTimer();
	Q_SLOT void cancelLockTimer();
	Q_SLOT void onThumbnail();

signals:
	void valueChanged(QString);
	void lockChanged(bool);

private:
	NavigationPane* mAppPage;
	QTimer* mTimer;
	int mLockoutTimer;
	QString mCurrentDatabase;
	QString m_sValue;
	bool mIsLocked;
    IDatabase* db;
    IGroupHandle* mCurrentGroup;
};

#endif /* DBCONTROLSERVICE_H_ */
