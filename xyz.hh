#pragma once

#include<compare>
#include<concepts>
#include<cstdlib>
#include"xyz.h"

namespace zlt {
  static inline constexpr size_t invSize = zltInvSize;
  static inline constexpr void *invPtr = zltInvPtr;

  template<class T>
  static inline constexpr T &pointTo(void *p) noexcept {
    return *(T *) p;
  }

  template<class T>
  static inline constexpr const T &pointTo(const void *p) noexcept {
    return *(const T *) p;
  }

  template<class T, class U>
  static inline constexpr T &memberOf(void *p, T U::*m) noexcept {
    return pointTo<U>(p).*m;
  }

  template<class T, class U>
  static inline constexpr const T &memberOf(const void *p, T U::*m) noexcept {
    return pointTo<U>(p).*m;
  }

  template<class T, class U>
  static inline constexpr size_t offsetOf(T U::*m) noexcept {
    U *u = nullptr;
    return (size_t) &(u->*m);
  }

  template<class U, class T>
  static inline constexpr U &containerOf(T &t, T U::*m) noexcept {
    return *(U *) ((void *) &t - offsetOf(m));
  }

  template<class U, class T>
  static inline constexpr const U &containerOf(const T &t, T U::*m) noexcept {
    return *(const U *) ((const void *) &t - offsetOf(m));
  }

  static inline void memSwap(void *a, void *b, size_t size) noexcept {
    zltMemSwap(a, b, size);
  }

  #ifdef __cpp_lib_three_way_comparison

  using Compare = std::compare_three_way;

  #else

  struct Compare {
    template<class T, class U>
    auto operator ()(T &&t, U &&u) const {
      return t <=> u;
    }
  };

  #endif

  /// overloaded function resolve
  template<class ...Args>
  struct OFR {
    template<class R>
    constexpr auto operator ()(R (*f)(Args...)) const noexcept {
      return f;
    }
  };

  // guard operations begin
  template<class Cleanup, class T>
  struct CleanupGuard {
    Cleanup cleanup;
    T &value;
    CleanupGuard(Cleanup &&cleanup, T &value) noexcept: cleanup(std::move(cleanup)), value(value) {}
    ~CleanupGuard() noexcept {
      cleanup(value);
    }
  };

  struct FreeGuard {
    void *&value;
    FreeGuard(void *&value) noexcept: value(value) {}
    ~FreeGuard() noexcept {
      free(value);
    }
  };

  template<std::invocable DoSth>
  struct Guard {
    DoSth doSth;
    Guard(DoSth &&doSth) noexcept: doSth(std::move(doSth)) {}
    ~Guard() noexcept {
      doSth();
    }
  };
  // guard operations end

  template<class T, size_t N = 1>
  static inline T *typeAlloc() noexcept {
    return (T *) malloc(sizeof(T) * N);
  }

  template<class T>
  static inline T *typeAlloc(size_t n) noexcept {
    return (T *) malloc(sizeof(T) * n);
  }
}
