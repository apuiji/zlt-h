#pragma once

namespace zlt {
  using Stack = zltStack;
}

namespace zlt::stack {
  static inline Stack make(void *data, size_t size) noexcept {
    return zltStackMake(data, size);
  }

  template<class T>
  static inline T &peek(const void *k) noexcept {
    return zltStackPeek(k, sizeof(T));
  }

  template<class T>
  static inline bool push(void *k, T &&t) noexcept {
    return zltStackPush(k, &t, sizeof(T));
  }

  static inline void pop(void *k, size_t size) noexcept {
    zltStackPop(k, size);
  }

  template<class T>
  static inline void pop(void *k) noexcept {
    pop(k, sizeof(T));
  }

  static inline void reAlloc(void *k, size_t size) noexcept {
    return zltStackRealloc(k, size);
  }
}
