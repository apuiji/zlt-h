#ifndef ZLT_STR_BUILD_H
#define ZLT_STR_BUILD_H

#include"stack.h"
#include"string.h"

#include"ifcpp_begin.h"

typedef struct {
  zltStack dest;
  zltStack buf;
} zltStrBuild;

static inline zltStrBuild zltStrBuildMake(zltStack dest, zltStack buf) {
  return (zltStrBuild) { .dest = dest, .buf = buf };
}

/// @return successfully write until
zltString zltStrBuildWrite(zltStrBuild *sb, zltString src);

bool zltStrBuildFlush(zltStrBuild *sb);

static inline zltString zltStrBuildProd(const zltStrBuild *sb) {
  return zltStrMake(sb->dest.data, zltStackSize(&sb->dest));
}

#include"ifcpp_end.h"

#endif
