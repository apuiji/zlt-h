#pragma once

#include"stack.hh"
#include"strbuild.h"
#include"string.hh"

namespace zlt {
  using StrBuild = zltStrBuild;
}

namespace zlt::strbuild {
  /// @see zltStrBuildWrite
  static inline bool write(StrBuild &sb, const void *data, size_t size) noexcept {
    return zltStrBuildWrite(&sb, data, size);
  }

  template<class T>
  static inline bool write(StrBuild &sb, T &&t) noexcept {
    using U = std::remove_reference_t<T>;
    return write(sb, &t, sizeof(U));
  }

  static inline bool writeStr(StrBuild &sb, const String &str) noexcept {
    return write(sb, str.data, str.size);
  }

  /// @see zltStrBuildUnwrite
  static inline void unwrite(StrBuild &sb, size_t n) noexcept {
    zltStrBuildUnwrite(&sb, n);
  }

  /// @see zltStrBuildFlush
  static inline bool flush(StrBuild &sb) noexcept {
    return zltStrBuildFlush(&sb);
  }

  /// @see zltStrBuildProd
  static inline String product(StrBuild &sb) noexcept {
    return zltStrBuildProd(&sb);
  }
}
