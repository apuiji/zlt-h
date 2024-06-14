#pragma once

#include"link.h"

namespace zlt {
  using Link = zltLink;
  using DbLink = zltDbLink;
}

namespace zlt::link {
  using Dtor = zltLinkDtor;

  static inline void clean(void *link, const void *end, Dtor *dtor) noexcept {
    zltLinkClean(link, end, dtor);
  }

  static inline void *&insert(void *&dest, void *link, void *last) noexcept {
    return *zltLinkInsert(&dest, link, last);
  }

  static inline void *&push(void *&dest, void *link) noexcept {
    return *zltLinkPush(&dest, link);
  }

  static inline void *erase(void *&dest, void *last) noexcept {
    return zltLinkErase(&dest, last);
  }

  static inline void *pop(void *&dest) noexcept {
    return zltLinkPop(&dest);
  }
}
