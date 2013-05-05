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
	Q_INVOKABLE bool charcodeIsLetter(int u);
	Q_INVOKABLE QString charcodeToQString(int u);

	/**
	 * This Invokable function gets a value from the QSettings,
	 * if that value does not exist in the QSettings database, the default value is returned.
	 *
	 * @param objectName Index path to the item
	 * @param defaultValue Used to create the data in the database when adding
	 * @return If the objectName exists, the value of the QSettings object is returned.
	 *         If the objectName doesn't exist, the default value is returned.
	 */
	Q_INVOKABLE QString getGlobalSettingFor(const QString &objectName, const QString &defaultValue);
	Q_INVOKABLE QString getDatabaseSettingFor(const QString &objectName, const QString &defaultValue);

	/**
	 * This function sets a value in the QSettings database. This function should to be called
	 * when a data value has been updated from QML
	 *
	 * @param objectName Index path to the item
	 * @param inputValue new value to the QSettings database
	 */
	Q_INVOKABLE void saveGlobalSettingFor(const QString &objectName, const QString &inputValue);
	Q_INVOKABLE void saveDatabaseSettingFor(const QString &objectName, const QString &inputValue);

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
	QString mCurrentDatabase;
	QString m_sValue;
	bool mIsLocked;
    IDatabase* db;
    IGroupHandle* mCurrentGroup;
};

#endif /* DBCONTROLSERVICE_H_ */
