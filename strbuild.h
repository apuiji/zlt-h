#ifndef ZLT_STR_BUILD_H
#define ZLT_STR_BUILD_H

#include"stack.h"
#include"string.h"

#include"ifcpp_begin.h"

zltString zltStrBuildWrite(zltStack *dest, zltStack *buf, zltString src);

bool zltStrBuildFlush(zltStack *dest, zltStack *buf);

static inline zltString zltStrBuildProd(const zltStack *k) {
  return zltStrMake(k->data, zltStackSize(k));
}

#include"ifcpp_end.h"

#endif
