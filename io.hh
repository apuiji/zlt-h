#include"io.h"
#include"string.hh"

namespace zlt::io {
  static inline size_t write(FILE *dest, String s) noexcept {
    return zltFwriteStr(dest, s);
  }

  struct CloseGuard {
    FILE *&file;
    CloseGuard(FILE *&file) noexcept: file(file) {}
    ~CloseGuard() noexcept {
      fclose(file);
    }
  };
}
