#ifndef ZLT_FSPATH_H
#define ZLT_FSPATH_H

#include"string.h"

#include"ifcpp_begin.h"

zltString zltFsPathParent(zltString path, zltString sep);
zltString zltFsPathName(zltString path, zltString sep);
zltString zltFsPathCanonical(char *dest, zltString path);

#include"ifcpp_end.h"

#endif
