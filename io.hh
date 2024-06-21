#include"io.h"
#include"string.hh"

namespace zlt::io {
  struct CloseGuard {
    FILE *&file;
    CloseGuard(FILE *&file) noexcept: file(file) {}
    ~CloseGuard() noexcept {
      fclose(file);
    }
  };

  static inline size_t read(void *dest, size_t size, FILE *src) noexcept {
    return fread(dest, 1, size, src);
  }

  template<class T>
  static inline size_t read(T *dest, size_t count, FILE *src) noexcept {
    return fread(dest, sizeof(T), count, src);
  }

  template<class T>
  static inline size_t read(T &dest, FILE *dest) noexcept {
    return read(&dest, 1, src);
  }

  static inline size_t write(FILE *dest, void *src, size_t size) noexcept {
    return fwrite(src, 1, size, dest);
  }

  template<class T>
  static inline size_t write(FILE *dest, T *src, size_t count) noexcept {
    return fwrite(src, sizeof(T), count, dest);
  }

  template<class T>
  static inline size_t write(FILE *dest, T &&src) noexcept {
    return write(dest, &src, 1);
  }

  static inline size_t writeStr(FILE *dest, String s) noexcept {
    return zltFwriteStr(dest, s);
  }

  template<size_t N>
  static inline size_t writeStr(FILE *dest, const char (&s)[N]) noexcept {
    return write(dest, string::make(s));
  }
}
