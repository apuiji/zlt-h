#ifndef ZLT_IO_H
#define ZLT_IO_H

#include<stdio.h>
#include"string.h"

#include"ifcpp_begin.h"

static inline size_t zltFwriteStr(FILE *dest, zltString s) {
  return fwrite(s.data, 1, s.size, dest);
}

#include"ifcpp_end.h"

#endif
