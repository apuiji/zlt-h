#pragma once

#include"string.h"

namespace zlt {
  int isDigitChar(int c, size_t base = 10) noexcept {
    return zltIsDigitChar(c, base);
  }

  using String = zltString;
}

namespace zlt::string {
  // make operations begin
  /// @see zltStrMake
  static inline String make(const char *data, size_t size) noexcept {
    return zltStrMake(data, size);
  }

  /// @see zltStrMakeBE
  static inline String make(const char *begin, const char *end) noexcept {
    return zltStrMakeBE(begin, end);
  }

  /// @see zltStrMakeSta
  template<size_t N>
  static inline String make(const char (&data)[N]) noexcept {
    return zltStrMake(data, N - 1);
  }
  // make operations end

  /// @see zltStrEnd
  static inline String end(const String &s) noexcept {
    return zltStrEnd(s);
  }

  /// @see zltStrEndBack
  static inline String endBack(const String &s, size_t n) noexcept {
    return zltStrEndBack(s, n);
  }

  /// @see zltStrForward
  static inline String forward(const String &s, size_t n) noexcept {
    return zltStrForward(s, n);
  }

  // comparisons begin
  /// @see zltStrEq
  static inline bool equals(const String &a, const String &b, strncmpFn *cmp = strncmp) noexcept {
    return zltStrEq(a, b, cmp);
  }

  /// @see zltStrCmp
  static inline int compare(const String &a, const String &b, strncmpFn *cmp = strncmp) noexcept {
    return zltStrCmp(a, b, cmp);
  }

  /// @see zltStrStartsWith
  static inline bool startsWith(const String &src, const String &starts, strncmpFn *cmp = strncmp) noexcept {
    return zltStrStartsWith(src, starts, cmp);
  }

  /// @see zltStrEndsWith
  static inline bool endsWith(const String &src, const String &ends, strncmpFn *cmp = strncmp) noexcept {
    return zltStrEndsWith(src, ends, cmp);
  }

  /// @see zltStrSame
  static inline size_t same(const String &a, const String &b, strncmpFn *cmp = strncmp) noexcept {
    return zltStrSame(a, b, cmp);
  }
  // comparisons end

  // trim operations begin
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
  // trim operations end

  // find operations begin
  /// @see zltStrFindChar
  static inline String findChar(const String &src, int c) noexcept {
    return zltStrFindChar(src, c);
  }

  /// @see zltStrFindStr
  static inline String findStr(const String &src, const String &str, strncmpFn *cmp = strncmp) noexcept {
    return zltStrFindStr(src, str, cmp);
  }

  using PredForFind = zltStrPredForFind;

  /// @see zltStrFindIf
  static inline String findIf(const String &src, PredForFind *pred) noexcept {
    return zltStrFindIf(src, pred);
  }

  // kmp begin
  /// @see zltKMPNextMake
  static inline void kmpNextMake(size_t *dest, const String &pat) noexcept {
    zltKMPNextMake(dest, pat);
  }

  /// @see zltStrKMPFind
  static inline String kmpFind(const String &src, const String &pat, size_t *nextv) noexcept {
    return zltStrKMPFind(src, pat, nextv);
  }
  // kmp end

  // reverse find operations begin
  /// @see zltStrRevFindChar
  static inline String revFindChar(const String &src, int c) noexcept {
    return zltStrRevFindChar(src, c);
  }

  /// @see zltStrRevFindStr
  static inline String revFindStr(const String &src, const String &str, strncmpFn *cmp = strncmp) noexcept {
    return zltStrRevFindStr(src, str, cmp);
  }

  /// @see zltStrRevFindIf
  static inline String revFindIf(const String &src, PredForFind *pred) noexcept {
    return zltStrRevFindIf(src, pred);
  }
  // reverse find operations end
  // find operations end

  /// @see zltStrToCase
  static inline void toCase(String &dest, const String &src, tocaseFn *tocase) noexcept {
    return zltStrToCase(dest, src, tocase);
  }

  static inline void toCase(String &s, tocaseFn *tocase) noexcept {
    return zltStrToCase(s, s, tocase);
  }

  // string to number operations begin
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
  // string to number operations end
}

namespace zlt::string::cmp_op {
  static inline bool operator ==(const String &a, const String &b) noexcept {
    return equals(a, b);
  }

  static inline bool operator !=(const String &a, const String &b) noexcept {
    return !(a == b);
  }

  static inline std::strong_ordering operator <=>(const String &a, const String &b) noexcept {
    return compare(a, b) <=> 0;
  }

  static inline bool operator <(const String &a, const String &b) noexcept {
    return compare(a, b) < 0;
  }

  static inline bool operator >(const String &a, const String &b) noexcept {
    return compare(a, b) > 0;
  }

  static inline bool operator <=(const String &a, const String &b) noexcept {
    return compare(a, b) <= 0;
  }

  static inline bool operator >=(const String &a, const String &b) noexcept {
    return compare(a, b) >= 0;
  }
}
