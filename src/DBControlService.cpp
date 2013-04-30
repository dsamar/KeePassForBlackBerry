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
#include <QTimer>
#include "DBControlService.h"
#include <bb/cascades/QmlDocument>
#include <bb/cascades/SceneCover>
#include <bb/system/Clipboard>

using namespace bb::cascades;

DBControlService::DBControlService(bb::cascades::Application *app)
: QObject(app), mLockoutTimer(), mCurrentDatabase()
{
	this->db = 0;
	this->mIsLocked = false;
	this->setLock(true);

	// create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument *qml = QmlDocument::create("asset:///main.qml");
    qml->setContextProperty("dbs", this);

    // Register the two data model types
    qmlRegisterType<KPBBGroupHandle>("DatabaseLibrary", 1, 0, "KPBBGroupHandle");
    qmlRegisterType<KPBBEntryHandle>("DatabaseLibrary", 1, 0, "KPBBEntryHandle");

    // The SceneCover is registered so that it can be used in QML
    qmlRegisterType<SceneCover>("bb.cascades", 1, 0, "SceneCover");

    // Since it is not possible to create an instance of the AbstractCover
    // it is registered as an uncreatable type (necessary for accessing
    // Application.cover).
    qmlRegisterUncreatableType<AbstractCover>("bb.cascades", 1, 0, "AbstractCover",
            "An AbstractCover cannot be created.");

    // create root object for the UI
    NavigationPane *root = qml->createRootObject<NavigationPane>();
    this->mAppPage = root;

    QObject::connect(app, SIGNAL(thumbnail()), this, SLOT( onThumbnail() ));

    mTimer = new QTimer(this);
    QObject::connect(mTimer, SIGNAL(timeout()), this, SLOT(setLockTimer()));
    QObject::connect(app, SIGNAL(fullscreen()), this, SLOT(cancelLockTimer()));

    // set created root object as a scene
    app->setScene(root);
}

DBControlService::~DBControlService()
{
	if (0 != this->mTimer)
	{
		delete(this->mTimer);
	}

	if(0 != this->db)
	{
		delete(this->db);
	}
}

QString DBControlService::value()
{
	return m_sValue;
}

void DBControlService::setValue(QString s) {
	this->m_sValue = s;
	emit valueChanged(m_sValue);
}

void DBControlService::unlockTrial()
{
	QString filePath("app/native/assets/testdb.kdb");
	QString password("testdb");
	bool readOnly = true;

	return this->unlock(filePath, password, QString::null, readOnly);
}

void DBControlService::unlock(
		QString filePath,
		QString password,
		QString keyfile,
		bool readOnly)
{
	if (!this->mIsLocked)
	{
		this->setValue("Invalid Operation. Database already open.");
		return;
	}

	// Check if file exists and filename is not null
	if ( filePath.isNull() || filePath.isEmpty() )
	{
		this->setValue("No database file given.");
		return;
	}

	this->db = new Kdb3Database();
	if (0 == this->db)
	{
		this->setValue("Database Error. Null Pointer Exception.");
		return;
	}

	if ( !db->setKey(password, keyfile) )
	{
		this->setValue(db->getError());
		return;
	}

	if ( !db->load(filePath, readOnly))
	{
		this->setValue(db->getError());
		return;
	}

	this->setLock(false);
	this->setValue("Success");

	// Initialize Timer settings.
	QSettings settings;
	this->mCurrentDatabase = filePath;
	QString savedTimer = this->getValueFor("lockoutTimerSetting", "30");
	this->mLockoutTimer = savedTimer.left(savedTimer.indexOf('.')).toInt();
	return;
}

void DBControlService::populateGroupDataModel()
{
	// Create the GroupDataModel by locating the corresponding QML component
	GroupDataModel *pModel = this->mAppPage->top()->findChild<GroupDataModel*>("groupDataModel");

	if (0 == pModel)
	{
		qDebug() << "Cannot find current page.";
		return;
	}

	pModel->clear();

	// Insert the data as instances of the Employee class
	QList<IEntryHandle*> entries = db->entries();
	for(QList<IEntryHandle*>::iterator it = entries.begin(), itEnd = entries.end(); it != itEnd; ++it)
	{
		KPBBEntryHandle* eh = new KPBBEntryHandle(*it);
		if (0 != eh)
		{
			pModel->insert(eh);
		}
	}
}

void DBControlService::searchText(const QString& searchString)
{
	// Create the GroupDataModel by locating the corresponding QML component
	GroupDataModel *pModel = this->mAppPage->top()->findChild<GroupDataModel*>("groupDataModel");

	if (0 == pModel)
	{
		qDebug() << "Cannot find current page.";
		return;
	}

	pModel->clear();

	// Insert the data as instances of the Employee class
	QList<IEntryHandle*> entries = db->search(0, searchString, false, false, false, 0);
	for(QList<IEntryHandle*>::iterator it = entries.begin(), itEnd = entries.end(); it != itEnd; ++it)
	{
		KPBBEntryHandle* eh = new KPBBEntryHandle(*it);
		if (0 != eh)
		{
			pModel->insert(eh);
		}
	}
}

QString DBControlService::getValueFor(const QString &objectName, const QString &defaultValue)
{
    QSettings settings;
    QString keyName = objectName;

    if ("lockoutTimerSetting" == objectName)
    {
    	keyName = this->mCurrentDatabase + keyName;
    }

    // If no value has been saved, return the default value.
    if (settings.value(keyName).isNull()) {
        return defaultValue;
    }

    // Otherwise, return the value stored in the settings object.
    return settings.value(keyName).toString();
}

void DBControlService::saveValueFor(const QString &objectName, const QString &inputValue)
{
    // A new value is saved to the application settings object.
    QSettings settings;
    QString keyName = objectName;

	if ("lockoutTimerSetting" == objectName && !this->mCurrentDatabase.isNull() && !this->mCurrentDatabase.isEmpty())
	{
		keyName = this->mCurrentDatabase + keyName;
		this->mLockoutTimer = inputValue.left(inputValue.indexOf('.')).toInt();
	}

    settings.setValue(keyName, QVariant(inputValue));
}

bool DBControlService::isLocked()
{
	return this->mIsLocked;
}

void DBControlService::setLock(bool b)
{
	if (this->mIsLocked != b)
	{
		if (b && 0 != this->db)
		{
			// Close the database connection if we're locking it.
			GroupDataModel *pModel = this->mAppPage->top()->findChild<GroupDataModel*>("groupDataModel");
			if (0 != pModel)
			{
				pModel->clear();
			}
			this->mCurrentDatabase = QString::null;
			if (0 != this->db)
			{
				this->db->close();
				delete this->db;
			}

			// Clear clipboard of any data that may be left over
			bb::system::Clipboard clipboard;
			clipboard.clear();
		}

		this->mIsLocked = b;
		emit lockChanged(b);
	}
}

void DBControlService::setLockTimer()
{
	if (!this->isLocked())
	{
		this->setLock(true);
	}
}

void DBControlService::onThumbnail()
{
	if (0 != mTimer)
	{
		if (!this->isLocked() && !mTimer->isActive())
		{
			int timer = this->mLockoutTimer*1000;
			mTimer->start(timer);
		}
	}
}

void DBControlService::cancelLockTimer()
{
	if (0 != mTimer)
	{
		mTimer->stop();
	}
}
