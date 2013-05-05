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

#include "XmlReader.h"

XmlReader::XmlReader() {
}

XmlReader::~XmlReader() {
}

const QString XmlBasePath = QDir::currentPath() + "/app/native/assets/XML/";				// Base path to the XML folder in your app

QVariantList XmlReader::LoadXML(const QString& xmlPath, const QString& rowType, const QVariantList& attributeList){

	// Setup the full path to the XML file
	//	And open a QFile for use by the XmlStreamReader
	QString XmlPath = XmlBasePath + xmlPath;
	QFile* XFile = new QFile(XmlPath);
	XFile->open(QIODevice::ReadOnly | QIODevice::Text);

	// Initialize the XML reader with the XML file
	QXmlStreamReader Xml(XFile);

	//
	// This is where the magic happens: Read the Attributes off of each entry entry and return a QList of Name/Value pairs
	QList< QVariantMap > Entries;
	while(!Xml.atEnd()){
		QXmlStreamReader::TokenType Token = Xml.readNext();

		if(Token == QXmlStreamReader::StartElement){
			if(Xml.name() == rowType) {
				// If this is an xml element that is named correctly, try to read the attributes
				QXmlStreamAttributes attributes = Xml.attributes();

				QVariantMap Entry;
				for(int i = 0; i < attributeList.length(); i++)
				{
					QString attribute = attributeList[i].toString();
					Entry[attribute] = attributes.value(attribute).toString();
				}

				Entries.append(Entry);
			}
		}
	}

	// Cleanup file handle
	XFile->close();

	// Convert to QVariantList for transfer to QML
	QVariantList QVList;
	for(int i = 0; i < Entries.length(); i++){
		QVariantMap map;
		QVList << Entries[i];
	}

	return QVList;
}
