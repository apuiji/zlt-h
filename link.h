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

/// @param link requires not null
/// @param last requires not null
void zltLinkInsert(zltLink **dest, zltLink *link, zltLink *last);

/// @param link requires not null
/// @return next slot of last inserted
zltLink **zltLinkInsertUntil(zltLink **dest, zltLink *link, zltLink *end);

/// @param link requires not null
static inline void zltLinkPush(zltLink **dest, zltLink *link) {
  zltLinkInsert(dest, link, link);
}

/// @param link requires not empty
/// @param last requires not null
void zltLinkErase(zltLink **link, zltLink *last);

/// @param link requires not empty
void zltLinkEraseUntil(zltLink **link, zltLink *end);

/// @param link requires not empty
static inline void zltLinkPop(zltLink **link) {
  zltLinkErase(link, *link);
}

#include"ifcpp_end.h"

#endif
