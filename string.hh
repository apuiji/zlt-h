#pragma once

#include"string.h"
#include"xyz.hh"

namespace zlt {
  int isDigitChar(int c, size_t base) noexcept {
    return zltIsDigitChar(c, base);
  }

  using String = zltString;

  // comparison begin
  static inline bool operator ==(const String &a, const String &b) noexcept {
    return zltStrEq(a, b);
  }

  static inline bool operator !=(const String &a, const String &b) noexcept {
    return !(a == b);
  }

  static inline std::strong_ordering operator <=>(const String &a, const String &b) noexcept {
    return zltStrCmp(a, b) <=> 0;
  }

  static inline bool operator <(const String &a, const String &b) noexcept {
    return (a <=> b) == std::strong_ordering::less;
  }

  static inline bool operator >(const String &a, const String &b) noexcept {
    return (a <=> b) == std::strong_ordering::greater;
  }

  static inline bool operator <=(const String &a, const String &b) noexcept {
    auto c = a <=> b;
    return c == std::strong_ordering::less || c == std::strong_ordering::equivalent;
  }

  static inline bool operator >=(const String &a, const String &b) noexcept {
    auto c = a <=> b;
    return c == std::strong_ordering::greater || c == std::strong_ordering::equivalent;
  }
  // comparison end
}

namespace zlt::string {
  /// @see zltStrMake
  static inline String make(const char *data, size_t size) noexcept {
    return zltStrMake(data, size);
  }

  /// @see zltStrMakeBE
  static inline String make(const char *begin, const char *end) noexcept {
    return zltStrMakeBE(begin, end);
  }

  /// @see zltStrMakeStatic
  template<size_t N>
  static inline constexpr String make(const char (&data)[N]) noexcept {
    return zltStrMake(data, N - 1);
  }

  /// @see zltStrClone
  static inline String clone(const String &s) noexcept {
    return zltStrClone(s);
  }

  /// @see zltStrForward
  static inline String forward(const String &s, size_t n) noexcept {
    return zltStrForward(s, n);
  }

  /// @see zltStrTrimStart
  static inline String trimStart(const String &s) noexcept {
    return zltStrTrimStart(s);
  }

  /// @see zltStrTrimEnd
  static inline String trimEnd(const String &s) noexcept {
    return zltStrTrimEnd(s);
  }

  /// @see zltStrTrim
  static inline String trim(const String &s) noexcept {
    return zltStrTrim(s);
  }

  using ToULongFn = zltStrToULongFn;

  /// @see zltStrToULong
  static inline String toULong(unsigned long &dest, const String &src, size_t base) noexcept {
    return zltStrToULong(&dest, src, base);
  }

  /// @see zltStrToLong
  static inline String toLong(unsigned long &dest, const String &src, size_t base, ToULongFn *toULong) noexcept {
    return zltStrToLong(&dest, src, base, toULong);
  }

  /// @see zltStrToLong
  template<class ToULong>
  String toLong(long &dest, const String &src, size_t base, ToULong &&toULong = string::toULong) noexcept {
    unsigned long &ul = reinterpret_cast<unsigned long &>(dest);
    if (*src.data == '+') {
      return toULong(ul, src, base);
    }
    if (*src.data == '-') {
      String s = toULong(ul, src, base);
      dest = -dest;
      return s;
    }
    return toULong(ul, src, base);
  }

  using ToUDoubleFn = zltStrToUDoubleFn;

  /// @see zltStrToUDouble
  static inline String toUDouble(double &dest, const String &src) noexcept {
    return zltStrToUDouble(&dest, src);
  }

  /// @see zltStrToDouble
  static inline String toDouble(double &dest, const String &src, ToUDoubleFn *toUDouble) noexcept {
    return zltStrToDouble(&dest, src, toUDouble);
  }

  /// @see zltStrToDouble
  template<class ToUDouble>
  String toDouble(double &dest, const String &src, ToUDouble &&toUDouble = string::toUDouble) noexcept {
    if (*src.data == '+') {
      return toUDouble(dest, src);
    }
    if (*src.data == '-') {
      String s = toUDouble(dest, src);
      dest = -dest;
      return s;
    }
    return toUDouble(dest, src);
  }
}
