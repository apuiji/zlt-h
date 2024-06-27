#pragma once

#include"stack.hh"
#include"strbuild.h"
#include"string.hh"

namespace zlt::strbuild {
  static inline bool write(Stack &dest, Stack &buf, const void *data, size_t size) noexcept {
    return zltStrBuildWrite(&dest, &buf, data, size);
  }

  template<class T>
  static inline bool write(Stack &dest, Stack &buf, T &&t) noexcept {
    using U = std::remove_reference_t<T>;
    return write(dest, buf, &t, sizeof(U));
  }

  static inline bool writeStr(Stack &dest, Stack &buf, const String &str) noexcept {
    return write(dest, buf, str.data, str.size);
  }

  static inline bool flush(Stack &dest, Stack &buf) noexcept {
    return zltStrBuildFlush(&dest, &buf);
  }

  static inline String product(const Stack &k) noexcept {
    return zltStrBuildProd(&k);
  }
}
