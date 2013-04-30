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
