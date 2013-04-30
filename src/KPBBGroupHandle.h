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
