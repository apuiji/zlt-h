#pragma once

#include"fspath.h"
#include"string.hh"

namespace zlt::fspath {
  static inline constexpr auto sep = zltFsPathSep;

  static inline String parent(const String &path) noexcept {
    return zltFsPathParent(path);
  }

  static inline String name(const String &path) noexcept {
    return zltFsPathName(path);
  }

  static inline String canonical(const String &path) noexcept {
    return zltFsPathCanonical(path);
  }
}
