#pragma once

#include"link.h"

namespace zlt {
  using Link = zltLink;
  using DbLink = zltDbLink;
}

namespace zlt::link {
  /// @see zltLinkMake
  static inline Link make(const Link *next = nullptr) noexcept {
    return zltLinkMake(next);
  }

  using Dtor = zltLinkDtor;

  /// @see zltLinkClean
  static inline void clean(Link *link, Dtor *dtor) noexcept {
    zltLinkClean(link, dtor);
  }

  template<class Dtor>
  void clean(Link *link, Dtor &&dtor) noexcept {
    while (link) {
      auto next = link->next;
      dtor(link);
      link = next;
    }
  }

  template<class Dtor>
  struct CleanGuard {
    Link *&link;
    Dtor dtor;
    CleanGuard(Link *&link, const Dtor &dtor): link(link), dtor(dtor) {}
    CleanGuard(Link *&link, Dtor &&dtor) noexcept: link(link), dtor(std::move(dtor)) {}
    ~CleanGuard() noexcept {
      clean(link, dtor);
    }
  };

  /// @see zltLinkInsert
  static inline void insert(Link *&dest, Link *link, Link *last) noexcept {
    zltLinkInsert(&dest, link, last);
  }

  /// @see zltLinkInsertUntil
  static inline void insertUntil(Link *&dest, Link *link, Link *end = nullptr) noexcept {
    zltLinkInsertUntil(&dest, link, end);
  }

  /// @see zltLinkPush
  static inline void push(Link *&dest, Link *link) noexcept {
    zltLinkPush(&dest, link);
  }

  /// @see zltLinkErase
  static inline void erase(Link *&link, Link *last) noexcept {
    zltLinkErase(&link, last);
  }

  /// @see zltLinkEraseUntil
  static inline void eraseUntil(Link *&link, Link *end = nullptr) noexcept {
    zltLinkEraseUntil(&link, end);
  }

  /// @see zltLinkPop
  static inline void pop(Link *&link) noexcept {
    zltLinkPop(&link);
  }
}
