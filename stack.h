#ifndef ZLT_STACK_H
#define ZLT_STACK_H

#include<string.h>
#include"string.h"
#include"xyz.h"

#include"ifcpp_begin.h"

typedef struct {
  void *data;
  void *top;
  size_t left;
} zltStack;

#define zltStackMemb(p, m) zltMemb(p, zltStack, m)

static inline zltStack zltStackMake(void *data, size_t size) {
  return (zltStack) { .data = data, .top = data, .left = size };
}

static inline size_t zltStackSize(const void *k) {
  return zltStackMemb(k, top) - zltStackMemb(k, data);
}

static inline size_t zltStackCapacity(const void *k) {
  return zltStackSize(k) + zltStackMemb(k, left);
}

/// @param[out] dest requires not null
/// @param k requires not null and stored data size greater than param size
static inline void *zltStackPeek(const void *k, size_t size) {
  return zltStackMemb(k, top) - size;
}

/// @param k requires not null
void zltStackPush(void *k, const void *data, size_t size);

static inline void zltStackPushStr(void *k, zltString str) {
  zltStackPush(k, str.data, str.size);
}

/// @param k requires not null
/// @param size requires less than param k left
static inline void zltStackPop(void *k, size_t size) {
  zltStackMemb(k, top) -= size;
  zltStackMemb(k, left) += size;
}

/// @param k requires not null
/// @return false when bad
bool zltStackReCapacity(void *k, size_t capacity);

#include"ifcpp_end.h"

#endif
