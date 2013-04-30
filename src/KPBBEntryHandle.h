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

#ifndef KPBBENTRYHANDLE_H_
#define KPBBENTRYHANDLE_H_

#include <QObject>
#include <qmutex.h>
#include "Database.h"
#include <bb/system/InvokeManager>
#include <bb/system/InvokeRequest>
#include <bb/system/InvokeTargetReply>
#include <bb/system/Clipboard>

class KPBBEntryHandle : public QObject, public IEntryHandle {
    Q_OBJECT
    Q_PROPERTY(KpxUuid uuid READ uuid FINAL)
    Q_PROPERTY(IGroupHandle* group READ group FINAL)
    Q_PROPERTY(quint32 image READ image WRITE setImage FINAL)
    Q_PROPERTY(int visualIndex READ visualIndex WRITE setVisualIndex FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle FINAL)
    Q_PROPERTY(QString url READ url WRITE setUrl FINAL)
    Q_PROPERTY(QString username READ username WRITE setUsername FINAL)
    Q_PROPERTY(SecString password READ password WRITE setPassword FINAL)
    Q_PROPERTY(QString passwordUnlocked READ passwordUnlocked FINAL)
    Q_PROPERTY(QString comment READ comment WRITE setComment FINAL)
    Q_PROPERTY(QString binaryDesc READ binaryDesc WRITE setBinaryDesc FINAL)
    Q_PROPERTY(KpxDateTime creation READ creation WRITE setCreation FINAL)
    Q_PROPERTY(KpxDateTime lastMod READ lastMod WRITE setLastMod FINAL)
    Q_PROPERTY(KpxDateTime lastAccess READ lastAccess WRITE setLastAccess FINAL)
    Q_PROPERTY(KpxDateTime expire READ expire WRITE setExpire FINAL)
    Q_PROPERTY(QByteArray binary READ binary WRITE setBinary FINAL)
    Q_PROPERTY(quint32 binarySize READ binarySize FINAL)
    Q_PROPERTY(QString friendlySize READ friendlySize FINAL)
    Q_PROPERTY(bool isValid READ isValid FINAL)
    Q_PROPERTY(CEntry data READ data FINAL)

public:
    KPBBEntryHandle();
    KPBBEntryHandle(IEntryHandle* entryHandle);

    Q_INVOKABLE void copyPasswordToClipboard();
    Q_INVOKABLE void copyUsernameToClipboard();
    Q_INVOKABLE void launchBrowser();

	KpxUuid uuid() const;
	IGroupHandle* group() const;
	quint32 image() const;
	int visualIndex() const;
	QString title() const;
	QString url() const;
	QString username() const;
	SecString password() const;
	QString passwordUnlocked();
	QString comment() const;
	QString binaryDesc() const;
	KpxDateTime creation() const;
	KpxDateTime lastMod() const;
	KpxDateTime lastAccess() const;
	KpxDateTime expire() const;
	QByteArray binary() const;
	quint32 binarySize() const;
	QString friendlySize() const;
	bool isValid() const;
	CEntry data() const;

    Q_SLOT void setImage(const quint32& ImageID);
    Q_SLOT void setVisualIndex(int i);
	Q_SLOT void setTitle(const QString& Title);
	Q_SLOT void setUrl(const QString& URL);
	Q_SLOT void setUsername(const QString& Username);
	Q_SLOT void setPassword(const SecString& Password);
	Q_SLOT void setComment(const QString& Comment);
	Q_SLOT void setBinaryDesc(const QString& BinaryDesc);
	Q_SLOT void setCreation(const KpxDateTime& Creation);
	Q_SLOT void setLastMod(const KpxDateTime& LastMod);
	Q_SLOT void setLastAccess(const KpxDateTime& LastAccess);
	Q_SLOT void setExpire(const KpxDateTime& Expire);
	Q_SLOT void setBinary(const QByteArray& BinaryData);

	void setVisualIndexDirectly(int i);
private:
	QMutex mMutex;
	IEntryHandle* mEntryHandle;
};

#endif /* KPBBGROUPHANDLE_H_ */
