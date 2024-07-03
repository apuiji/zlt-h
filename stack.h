#ifndef ZLT_STACK_H
#define ZLT_STACK_H

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

static inline size_t zltStackSize(const zltStack *k) {
  return (char *) k->top - (char *) k->data;
}

static inline size_t zltStackCapacity(const zltStack *k) {
  return zltStackSize(k) + k->left;
}

/// @param k requires not null and stored data size greater than param size
static inline void *zltStackPeek(const zltStack *k, size_t size) {
  return (char *) k->top - size;
}

/// @param k requires not null
void zltStackPush(zltStack *k, const void *data, size_t size);

/// @param k requires not null
static inline void zltStackPushStr(zltStack *k, zltString str) {
  zltStackPush(k, str.data, str.size);
}

/// @param k requires not null
/// @param size requires less than param k left
static inline void zltStackPop(zltStack *k, size_t size) {
  k->top -= size;
  k->left += size;
}

/// @param k requires not null
/// @return false when bad
bool zltStackReCapacity(zltStack *k, size_t capacity);

#include"ifcpp_end.h"

#endif
