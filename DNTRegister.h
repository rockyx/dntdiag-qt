#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_REGISTER_H__
#define __DNT_REGISTER_H__

#include <DNTGlobal.h>

class DNT_DIAG_DECL RRegister
{
public:
  static void init(const QString &path);
  static bool check();
  static QString idCode();
  static void save(const QString &text);
};


#endif // __DNT_REGISTER_H__
