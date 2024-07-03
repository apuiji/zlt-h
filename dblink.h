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

/// @return the node which next is param end
zltDbLink *zltDbLinkFindUntil(const zltDbLink *link, const zltDbLink *end);

/// @param dest requires not null
/// @param link requires not null
/// @param last requires not null
static inline void zltDbLinkInsertAfter(zltDbLink *dest, zltDbLink *link, zltDbLink *last) {
  last->next = dest->next;
  dest->next = link;
}

/// @param dest requires not null
/// @param link requires not null
static inline void zltDbLinkPushAfter(zltDbLink *dest, zltDbLink *link) {
  zltDbLinkInsertAfter(dest, link, link);
}

/// @param dest requires not null
/// @param link requires not null
/// @param last requires not null
static inline void zltDbLinkInsertBefore(zltDbLink *dest, zltDbLink *link, zltDbLink *last) {
  link->prev = dest->prev;
  dest->prev = last;
}

/// @param dest requires not null
/// @param link requires not null
static inline void zltDbLinkPushBefore(zltDbLink *dest, zltDbLink *link) {
  zltDbLinkInsertBefore(dest, link, link);
}

/// @param link requires not null
/// @param last requires not null
void zltDbLinkErase(zltDbLink *link, zltDbLink *last);

/// @param link requires not null
static inline void zltDbLinkPop(zltDbLink *link) {
  zltDbLinkErase(link, link);
}

#include"ifcpp_end.h"

#endif
