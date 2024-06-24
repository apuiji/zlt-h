#pragma once

#include"filesystem.h"
#include"string.hh"

namespace zlt::filesystem {
  static inline String parentPath(const String &path) noexcept {
    return zltParentPath(path);
  }

  static inline String fileNamePath(const String &path) noexcept {
    return zltFileNamePath(path);
  }

  static inline String canonicalPath(const String &path) noexcept {
    return zltCanonicalPath(path);
  }
}
