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

#include "KPBBGroupHandle.h"
#include "Kdb3Database.h"

KPBBGroupHandle::KPBBGroupHandle()
{
}

KPBBGroupHandle::KPBBGroupHandle(IGroupHandle* groupHandle)
{
	this->mGroupHandle = groupHandle;
}

QString KPBBGroupHandle::title() {
	return this->mGroupHandle->title();
}

quint32 KPBBGroupHandle::image() {
	return this->mGroupHandle->image();
}

IGroupHandle* KPBBGroupHandle::parent() {
	return this->mGroupHandle->parent();
}

QList<IGroupHandle*> KPBBGroupHandle::children() {
	return this->mGroupHandle->children();
}

int KPBBGroupHandle::index() {
	return this->mGroupHandle->index();
}

bool KPBBGroupHandle::isValid() {
	return this->mGroupHandle->isValid();
}

int KPBBGroupHandle::level() {
	return this->mGroupHandle->level();
}

bool KPBBGroupHandle::expanded() {
	return this->mGroupHandle->expanded();
}

void KPBBGroupHandle::setExpanded(bool isExpanded) {
	this->mGroupHandle->setExpanded(isExpanded);
}

void KPBBGroupHandle::setTitle(const QString& title) {
	this->mGroupHandle->setTitle(title);
}

void KPBBGroupHandle::setImage(const quint32& imageId) {
	this->mGroupHandle->setImage(imageId);
}
