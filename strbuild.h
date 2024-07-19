#ifndef ZLT_STR_BUILD_H
#define ZLT_STR_BUILD_H

#include"stack.h"
#include"string.h"

#include"ifcpp_begin.h"

typedef struct {
  zltStack dest;
  zltStack buf;
} zltStrBuild;

/// @return successfully write until
zltString zltStrBuildWrite(zltStrBuild *sb, zltString src);

void zltStrBuildUnwrite(zltStrBuild *sb, size_t n);

bool zltStrBuildFlush(zltStrBuild *sb);

zltString zltStrBuildProd(zltStrBuild *sb);

#include"ifcpp_end.h"

#endif
