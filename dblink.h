#ifndef ZLT_DBLINK_H
#define ZLT_DBLINK_H

#include"ifcpp_begin.h"

typedef struct zltDbLink zltDbLink;

struct zltDbLink {
  zltDbLink *next;
  zltDbLink *prev;
};

static inline zltDbLink zltDbLinkMake(const zltDbLink *next, const zltDbLink *prev) {
  return (zltDbLink) { .next = (zltDbLink *) next, .prev = (zltDbLink *) prev };
}

/// @param dest requires not null
/// @param link requires not null
/// @param last requires not null
void zltDbLinkInsertAfter(zltDbLink *dest, zltDbLink *link, zltDbLink *last);

/// @param dest requires not null
/// @param link requires not null
void zltDbLinkInsertUntilAfter(zltDbLink *dest, zltDbLink *link, zltDbLink *end);

/// @param dest requires not null
/// @param link requires not null
static inline void zltDbLinkPushAfter(zltDbLink *dest, zltDbLink *link) {
  zltDbLinkInsertAfter(dest, link, link);
}

/// @param dest requires not null
/// @param link requires not null
/// @param last requires not null
void zltDbLinkInsertBefore(zltDbLink *dest, zltDbLink *link, zltDbLink *last);

/// @param dest requires not null
/// @param link requires not null
void zltDbLinkInsertUntilBefore(zltDbLink *dest, zltDbLink *link, zltDbLink *end);

/// @param dest requires not null
/// @param link requires not null
static inline void zltDbLinkPushBefore(zltDbLink *dest, zltDbLink *link) {
  zltDbLinkInsertBefore(dest, link, link);
}

/// @param link requires not null
/// @param last requires not null
void zltDbLinkErase(zltDbLink *link, zltDbLink *last);

/// @param link requires not null
void zltDbLinkEraseUntil(zltDbLink *link, zltDbLink *end);

/// @param link requires not null
static inline void zltDbLinkPop(zltDbLink *link) {
  zltDbLinkErase(link, link);
}

#include"ifcpp_end.h"

#endif
