#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_SYSTEM_DB_H__
#define __DNT_SYSTEM_DB_H__

#include <QString>
#include <DNTGlobal.h>

class DNT_DIAG_DECL DNTSystemDB
{
public:
  static void init(const QString &path);
  static QString queryText(const QString &name);
};

#endif // __DNT_SYSTEM_DB_H__
