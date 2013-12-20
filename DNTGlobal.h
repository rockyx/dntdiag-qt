#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_GLOBAL_H__
#define __DNT_GLOBAL_H__

#ifndef Q_MOC_RUN
#include <dnt/RTypeDefs.h>
#endif
#include <QtGlobal>
#include <QMetaType>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QSharedPointer>
#include <QSharedDataPointer>
#include <QString>
#include <QByteArray>
#include <QVector>
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <QtConcurrent/QtConcurrent>

#ifdef DNTDIAG_BUILD
#define DNT_DIAG_DECL Q_DECL_EXPORT
#else
#define DNT_DIAG_DECL Q_DECL_IMPORT
#endif

#ifdef DNTECU_BUILD
#define DNT_ECU_DECL Q_DECL_EXPORT
#else
#define DNT_ECU_DECL Q_DECL_IMPORT
#endif

#endif // __R_GLOBAL_H__
