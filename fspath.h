#ifndef ZLT_FSPATH_H
#define ZLT_FSPATH_H

#include"string.h"

#include"ifcpp_begin.h"

#ifdef WIN32

#define zltFsPathSep "\\"

#else

#define zltFsPathSep "/"

#endif

zltString zltFsPathParent(zltString path);
zltString zltFsPathName(zltString path);
zltString zltFsPathCanonical(zltString path);

#include"ifcpp_end.h"

#endif
