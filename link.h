#ifndef ZLT_LINK_H
#define ZLT_LINK_H

#include"ifcpp_begin.h"

typedef struct zltLink zltLink;

struct zltLink {
  zltLink *next;
};

static inline zltLink zltLinkMake(const zltLink *next) {
  return (zltLink) { .next = (zltLink *) next };
}

typedef void zltLinkDtor(void *link);

void zltLinkClean(zltLink *link, zltLinkDtor *dtor);

/// @return the node which next is param end
zltLink *zltLinkFindUntil(const zltLink *link, const zltLink *end);

/// @param link requires not null
/// @param last requires not null
static inline void zltLinkInsert(zltLink **dest, zltLink *link, zltLink *last) {
  last->next = *dest;
  *dest = link;
}

/// @param link requires not null
static inline void zltLinkPush(zltLink **dest, zltLink *link) {
  zltLinkInsert(dest, link, link);
}

/// @param link requires not empty
/// @param last requires not null
static inline void zltLinkErase(zltLink **link, zltLink *last) {
  *link = last->next;
  last->next = NULL;
}

/// @param link requires not empty
static inline void zltLinkPop(zltLink **link) {
  zltLinkErase(link, *link);
}

#include"ifcpp_end.h"

#endif
