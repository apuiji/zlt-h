#ifndef ZLT_STACK_H
#define ZLT_STACK_H

#include<stdlib.h>
#include<string.h>
#include"string.h"

#include"ifcpp_begin.h"

typedef struct {
  void *data;
  void *top;
  size_t left;
} zltStack;

static inline zltStack zltStackMake(void *data, size_t size) {
  return (zltStack) { .data = data, .top = data, .left = size };
}

/// @return false when bad occurred
static inline bool zltStackMakeAlloc(zltStack *dest, size_t size) {
  void *data = malloc(size);
  if (!data) {
    return false;
  }
  *dest = zltStackMake(data, size);
  return true;
}

static inline size_t zltStackSize(const zltStack *k) {
  return (char *) k->top - (char *) k->data;
}

static inline size_t zltStackCapacity(const zltStack *k) {
  return zltStackSize(k) + k->left;
}

/// @param k requires not null
/// @param size requires not greater than param k size
static inline void *zltStackPeek(const zltStack *k, size_t size) {
  return (char *) k->top - size;
}

/// @param k requires not null
/// @param size requires not greater than param k left
void zltStackPush(zltStack *k, const void *data, size_t size);

/// @param k requires not null
/// @param str requires size not greater than param k left
static inline void zltStackPushStr(zltStack *k, zltString str) {
  zltStackPush(k, str.data, str.size);
}

/// @param k requires not null
/// @param size requires not greater than param k size
static inline void zltStackPop(zltStack *k, size_t size) {
  k->top -= size;
  k->left += size;
}

/// @param k requires not null
/// @return false when bad occurred
bool zltStackReCapacity(zltStack *k, size_t capacity);

#include"ifcpp_end.h"

#endif
