#ifndef ZLT_LINK_H
#define ZLT_LINK_H

#include"xyz.h"

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

typedef struct zltDbLink zltDbLink;

struct zltDbLink {
  zltDbLink *next;
  zltDbLink *prev;
};

static inline zltDbLink zltDbLinkMake(const zltDbLink *next, const zltDbLink *prev) {
  return (zltDbLink) { .next = (zltDbLink *) next, .prev = (zltDbLink *) prev };
}

/// @param link requires not null
/// @param last requires not null
void zltDbLinkInsertAfter(zltDbLink *dest, zltDbLink *link, zltDbLink *last);

/// @param link requires not null
void zltDbLinkInsertUntilAfter(zltDbLink *dest, zltDbLink *link, zltDbLink *end);

static inline void zltDbLinkPushAfter(zltDbLink *dest, zltDbLink *link) {
  zltDbLinkInsertAfter(dest, link, link);
}

/// @param link requires not null
/// @param last requires not null
void zltDbLinkInsertBefore(zltDbLink *dest, zltDbLink *link, zltDbLink *last);

/// @param link requires not null
void zltDbLinkInsertUntilBefore(zltDbLink *dest, zltDbLink *link, zltDbLink *end);

static inline void zltDbLinkPushBefore(zltDbLink *dest, zltDbLink *link) {
  zltDbLinkInsertBefore(dest, link, link);
}

void zltDbLinkErase(zltDbLink *link, zltDbLink *last);

void zltDbLinkEraseUntil(zltDbLink *link, zltDbLink *end);

static inline void zltDbLinkPop()

#include"ifcpp_end.h"

#endif
