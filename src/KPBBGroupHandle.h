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

#ifndef KPBBGROUPHANDLE_H_
#define KPBBGROUPHANDLE_H_

#include <QObject>
#include "Database.h"

class KPBBGroupHandle : public QObject, public IGroupHandle {
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle FINAL)
    Q_PROPERTY(quint32 image READ image WRITE setImage FINAL)
    Q_PROPERTY(bool expanded READ expanded WRITE setExpanded FINAL)

public:
    KPBBGroupHandle();
    KPBBGroupHandle(IGroupHandle* groupHandle);

	QString title();
	quint32 image();
	IGroupHandle* parent();
	QList<IGroupHandle*> children();
	int index();
	bool isValid();
	int level();
	bool expanded();

	Q_SLOT void setExpanded(bool);
	Q_SLOT void setTitle(const QString& Title);
	Q_SLOT void setImage(const quint32& ImageID);

private:
	IGroupHandle* mGroupHandle;
};

#endif /* KPBBGROUPHANDLE_H_ */
