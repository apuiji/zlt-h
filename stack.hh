#pragma once

#include"stack.h"
#include"xyz.hh"

namespace zlt {
  using Stack = zltStack;
}

namespace zlt::stack {
  static inline Stack make(void *data, size_t size) noexcept {
    return zltStackMake(data, size);
  }

  static inline size_t size(const void *k) noexcept {
    return zltStackSize(k);
  }

  static inline size_t capacity(const void *k) noexcept {
    return zltStackCapacity(k);
  }

  static inline void *peek(const void *k, size_t size) noexcept {
    return zltStackPeek(k, size);
  }

  template<class T>
  static inline T &peek(const void *k) noexcept {
    return pointTo<T>(peek(k, sizeof(T)));
  }

  static inline void push(void *k, const void *data, size_t size) noexcept {
    zltStackPush(k, data, size);
  }

  template<class T>
  static inline void push(void *k, T &&t) noexcept {
    using U = std::remove_reference_t<T>;
    push(k, &t, sizeof(U));
  }

  static inline void pop(void *k, size_t size) noexcept {
    zltStackPop(k, size);
  }

  template<class T>
  static inline void pop(void *k) noexcept {
    pop(k, sizeof(T));
  }

  static inline bool reCapacity(void *k, size_t capacity) noexcept {
    return zltStackReCapacity(k, capacity);
  }
}
