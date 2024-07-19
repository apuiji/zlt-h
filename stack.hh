#pragma once

#include"stack.h"
#include"string.hh"

namespace zlt {
  using Stack = zltStack;
}

namespace zlt::stack {
  /// @see zltStackMake
  static inline Stack make(void *data, size_t size) noexcept {
    return zltStackMake(data, size);
  }

  template<class T, size_t N>
  static inline Stack make(T (&data)[N]) noexcept {
    return make(data, sizeof(T) * N);
  }

  /// @see zltStackMakeAlloc
  static inline bool make(Stack &dest, size_t size) noexcept {
    return zltStackMakeAlloc(&dest, size);
  }

  /// @see zltStackSize
  static inline size_t size(const Stack &k) noexcept {
    return zltStackSize(&k);
  }

  /// @see zltStackCapacity
  static inline size_t capacity(const Stack &k) noexcept {
    return zltStackCapacity(&k);
  }

  /// @see zltStackPeek
  static inline void *peek(const Stack &k, size_t size) noexcept {
    return zltStackPeek(&k, size);
  }

  template<class T>
  static inline T *peek(const Stack &k) noexcept {
    return (T *) peek(k, sizeof(T));
  }

  /// @see zltStackPush
  static inline void push(Stack &k, const void *data, size_t size) noexcept {
    zltStackPush(&k, data, size);
  }

  template<class T>
  static inline void push(Stack &k, T &&t) noexcept {
    using U = std::remove_reference_t<T>;
    push(k, &t, sizeof(U));
  }

  static inline void pushStr(Stack &k, const String &s) noexcept {
    push(k, s.data, s.size);
  }

  /// @see zltStackPop
  static inline void pop(Stack &k, size_t size) noexcept {
    zltStackPop(&k, size);
  }

  template<class T>
  static inline void pop(Stack &k) noexcept {
    pop(k, sizeof(T));
  }

  /// @see zltStackReCapacity
  static inline bool reCapacity(Stack &k, size_t capacity) noexcept {
    return zltStackReCapacity(&k, capacity);
  }
}
