#pragma once

#include<cstdlib>
#include"xyz.hh"

namespace zlt {
  struct FreeGuard {
    void *&value;
    FreeGuard(void *&value) noexcept: value(value) {}
    ~FreeGuard() noexcept {
      free(value);
    }
  };

  template<std::invocable T>
  struct Guard {
    T t;
    Guard(T &&t) noexcept: t(std::move(t)) {}
    ~Guard() noexcept {
      t();
    }
  };
}
