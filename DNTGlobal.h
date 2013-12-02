#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_GLOBAL_H__
#define __DNT_GLOBAL_H__

#include <QtGlobal>
#include <QSharedPointer>
#ifndef Q_MOC_RUN
#include <dnt/RTypeDefs.h>
#endif

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

class DNTSerialPortThread;
typedef QSharedPointer<DNTSerialPortThread> DNTSerialPortThreadPtr;

#endif // __R_GLOBAL_H__
