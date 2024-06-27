#ifndef ZLT_STR_BUILD_H
#define ZLT_STR_BUILD_H

#include"stack.h"
#include"string.h"

#include"ifcpp_begin.h"

bool zltStrBuildWrite(zltStack *dest, zltStack *buf, const void *data, size_t size);

static inline bool zltStrBuildWriteStr(zltStack *dest, zltStack *buf, zltString str) {
  return zltStrBuildWrite(dest, buf, str.data, str.size);
}

bool zltStrBuildFlush(zltStack *dest, zltStack *buf);

static inline zltString zltStrBuildProd(const zltStack *k) {
  return zltStrMake(k->data, zltStackSize(k));
}

#include"ifcpp_end.h"

#endif
