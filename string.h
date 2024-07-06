#ifndef ZLT_STRING_H
#define ZLT_STRING_H

#include<ctype.h>
#include<stdbool.h>
#include<stddef.h>

#include"zlt/ifcpp_begin.h"

/// @param base see param base of stotol
/// @return -1 when not a based digit character
int zltIsDigitChar(int c, size_t base);

typedef struct {
  char *data;
  size_t size;
} zltString;

static inline zltString zltStrMake(const char *data, size_t size) {
  return (zltString) { .data = (char *) data, .size = size };
}

static inline zltString zltStrMakeBE(const char *begin, const char *end) {
  return zltStrMake(begin, end - begin);
}

/// @param data requires string constant literal
#define zltStrMakeSta(data) zltStrMake(data, sizeof(data) - 1)

static inline zltString zltStrEnd(zltString src) {
  return zltStrMake(src.data + src.size, 0);
}

// comparisons begin
bool zltStrEq(zltString a, zltString b);
int zltStrCmp(zltString a, zltString b);
bool zltStrStarts(zltString src, zltString starts);
bool zltStrEnds(zltString src, zltString ends);

// icase begin
bool zltStrEqIcase(zltString a, zltString b);
int zltStrCmpIcase(zltString a, zltString b);
bool zltStrStartsIcase(zltString src, zltString starts);
bool zltStrEndsIcase(zltString src, zltString ends);
// icase end
// comparisons end

static inline zltString zltStrForward(zltString src, int n) {
  return zltStrMake(src.data + n, src.size - n);
}

zltString zltStrTrimStart(zltString str);
zltString zltStrTrimEnd(zltString str);

static inline zltString zltStrTrim(zltString str) {
  return zltStrTrimEnd(zltStrTrimStart(str));
}

void zltStrToUpper(zltString dest, zltString src);
void zltStrToLower(zltString dest, zltString src);
// string to number operations begin
typedef zltString zltStrToULongFn(unsigned long *dest, zltString src, size_t base);

/// match /^[+-]?{{toULong}}/
/// @return left contents after parse
zltString zltStrToLong(long *dest, zltString src, size_t base, zltStrToULongFn *toULong);

/// different of stdlib strtoul below
///   - match /^[[:base-n-digit:]]+/
///   - ignore bads like out-of-range
/// @param[out] dest usually initialized by 0
/// @return left contents after parse
zltString zltStrToULong(unsigned long *dest, zltString src, size_t base);

typedef zltString zltStrToUDoubleFn(double *dest, zltString src);

/// match /^[+-]?{{toUDouble}}/
/// @return left contents after parse
zltString zltStrToDouble(double *dest, zltString src, zltStrToUDoubleFn *toUDouble);

/// different of stdlib strtod below
///   - match /^(\d+\.\d*|\.\d+)([Ee][+-]?\d+)?/
///   - ignore bads like out-of-range
/// @param[out] dest usually initialized by 0
/// @return left contents after parse
zltString zltStrToUDouble(double *dest, zltString src);
// string to number operations end

#include"zlt/ifcpp_end.h"

#endif
