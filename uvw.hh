#pragma once

#include<utility>

namespace zlt {
  template<class ...T>
  struct Dynamicastable {
    template<class U>
    requires (std::is_pointer_v<U>)
    bool operator ()(const U u) noexcept {
      return u && (dynamic_cast<const T*>(u) || ...);
    }
    template<class U>
    requires (!std::is_pointer_v<U>)
    bool operator ()(const U &u) noexcept {
      return operator ()(&u);
    }
  };

  template<class T>
  static inline T remove(T &t) noexcept {
    return std::move(t);
  }
}
