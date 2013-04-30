/***************************************************************************
 *   Copyright (C) 2005 by Tarek Saidi                                     *
 *   mail@tarek-saidi.de                                                   *
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

#include "random.h"
#include <qglobal.h>
#include <process.h>
#include "yarrow.h"
#include <huseed.h>

#if defined(Q_WS_X11) || defined(Q_WS_MAC)
	#include <QFile>
#elif defined(Q_WS_WIN)
	#include <windows.h>
	#include <wincrypt.h>
	#include <QSysInfo>
#endif

#include <QCryptographicHash>
#include <QDataStream>
#include <QTime>

void initStdRand();

void getEntropy(quint8* buffer, int length){
	initStdRand();
	for(int i=0;i<length;i++){
		((quint8*)buffer)[i] = (quint8) (qrand()%256);
	}
}

quint32 randint(quint32 limit){
	quint32 rand;
	randomize(&rand, 4);
	return (rand % limit);
}

quint32 randintRange(quint32 min, quint32 max){
	return min + randint(max-min+1);
}

extern void initStdRand(){
	static bool initalized = false;
	if (initalized)
		return;
	
	QByteArray buffer;
	QDataStream stream(&buffer, QIODevice::WriteOnly);
	
	stream << QDateTime::currentDateTime().toTime_t();
	stream << QTime::currentTime().msec();
#ifdef Q_WS_WIN
	stream << (quint32) GetCurrentProcessId();
#else
	stream << getpid();
#endif
	/* On a modern OS code, stack and heap base are randomized */
	quint64 code_value = (quint64)initStdRand;
	stream << code_value;
	stream << (quint64)&code_value;
	
	QByteArray hash = QCryptographicHash::hash(buffer, QCryptographicHash::Sha1);
	
	qsrand( *((uint*) hash.data()) );
	initalized = true;
}
