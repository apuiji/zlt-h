#pragma once

#include"fspath.h"
#include"string.hh"

namespace zlt::fspath {
  /// @see zltFsPathParent
  static inline String parent(const String &path, const String &sep = string::make("/")) noexcept {
    return zltFsPathParent(path, sep);
  }

  /// @see zltFsPathName
  static inline String name(const String &path, const String &sep = string::make("/")) noexcept {
    return zltFsPathName(path, sep);
  }

  /// @see zltFsPathCanonical
  static inline String canonical(char *dest, const String &path) noexcept {
    return zltFsPathCanonical(dest, path);
  }
}
