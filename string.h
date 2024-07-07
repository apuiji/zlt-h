#ifndef ZLT_STRING_H
#define ZLT_STRING_H

#include<ctype.h>
#include<stdbool.h>
#include<stddef.h>
#include<string.h>

#include"zlt/ifcpp_begin.h"

/// @param base see param base of stotol
/// @return -1 when not a based digit character
int zltIsDigitChar(int c, size_t base);

typedef struct {
  char *data;
  size_t size;
} zltString;

// make operations begin
static inline zltString zltStrMake(const char *data, size_t size) {
  return (zltString) { .data = (char *) data, .size = size };
}

static inline zltString zltStrMakeBE(const char *begin, const char *end) {
  return zltStrMake(begin, end - begin);
}

/// @param data requires string constant literal
#define zltStrMakeSta(data) zltStrMake(data, sizeof(data) - 1)
// make operations end

static inline zltString zltStrEnd(zltString src) {
  return zltStrMake(src.data + src.size, 0);
}

static inline zltString zltStrEndBack(zltString src, size_t n) {
  return zltStrMake(src.data + src.size - n, n);
}

static inline zltString zltStrForward(zltString src, int n) {
  return zltStrMake(src.data + n, src.size - n);
}

// comparisons begin
/// usually strncmp or strncasecmp
typedef int strncmpFn(const char *, const char *, size_t);

static inline bool zltStrEq(zltString a, zltString b, strncmpFn *cmp) {
  return a.size == b.size && !cmp(a.data, b.data, a.size);
}

int zltStrCmp(zltString a, zltString b, strncmpFn *cmp);

static inline bool zltStrStartsWith(zltString src, zltString starts, strncmpFn *cmp) {
  return src.size == starts.size && !cmp(src.data, starts.data, starts.size);
}

static inline bool zltStrEndsWith(zltString src, zltString ends, strncmpFn *cmp) {
  return src.size == ends.size && !cmp(src.data + src.size - ends.size, ends.data, ends.size);
}

/// @return count of same content between param a and param b
size_t zltStrSame(zltString a, zltString b, strncmpFn *cmp);
// comparisons end

// trim operations begin
zltString zltStrTrimStart(zltString str);
zltString zltStrTrimEnd(zltString str);

static inline zltString zltStrTrim(zltString str) {
  return zltStrTrimEnd(zltStrTrimStart(str));
}
// trim operations end

// find operations begin
typedef bool zltStrPredForFind(zltString src);

zltString zltStrFindIf(zltString src, zltStrPredForFind *pred);
zltString zltStrRevFindIf(zltString src, zltStrPredForFind *pred);

// kmp begin
/// @param pat length aleast 2
void zltKMPNextMake(size_t *dest, zltString pat);

zltString zltStrKMPFind(zltString src, zltString pat, size_t *nextv);
// kmp end
// find operations end

/// usually toupper or tolower
typedef int tocaseFn(int);

void zltStrToCase(zltString dest, zltString src, tocaseFn *tocase);

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
