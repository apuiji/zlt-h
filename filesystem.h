#ifndef ZLT_FILESYSTEM_H
#define ZLT_FILESYSTEM_H

#include"string.h"

#include"ifcpp_begin.h"

zltString zltFSParentPath(zltString path);
zltString zltFSFileNamePath(zltString path);
zltString zltFSCanonicalPath(zltString path);

#include"ifcpp_end.h"

#endif
