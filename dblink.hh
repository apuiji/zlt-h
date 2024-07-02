#pragma once

#include"dblink.h"

namespace zlt {
  using DbLink = zltDbLink;
}

namespace zlt::dblink {
  /// @see zltDbLinkMake
  static inline DbLink make(const DbLink *next = nullptr, const DbLink *prev = nullptr) noexcept {
    return zltDbLinkMake(next, prev);
  }

  /// @see zltDbLinkInsertAfter
  static inline void insertAfter(DbLink *dest, DbLink *link, DbLink *last) noexcept {
    zltDbLinkInsertAfter(dest, link, last);
  }

  /// @see zltDbLinkInsertUntilAfter
  static inline void insertUntilAfter(DbLink *dest, DbLink *link, DbLink *end = nullptr) noexcept {
    zltDbLinkInsertUntilAfter(dest, link, end);
  }

  /// @see zltDbLinkPushAfter
  static inline void pushAfter(DbLink *dest, DbLink *link) noexcept {
    zltDbLinkPushAfter(dest, link);
  }

  /// @see zltDbLinkInsertBefore
  static inline void insertBefore(DbLink *dest, DbLink *link, DbLink *last) noexcept {
    zltDbLinkInsertBefore(dest, link, last);
  }

  /// @see zltDbLinkInsertUntilBefore
  static inline void insertUntilBefore(DbLink *dest, DbLink *link, DbLink *end = nullptr) noexcept {
    zltDbLinkInsertUntilBefore(dest, link, end);
  }

  /// @see zltDbLinkPushBefore
  static inline void pushBefore(DbLink *dest, DbLink *link) noexcept {
    zltDbLinkPushBefore(dest, link);
  }

  /// @see zltDbLinkErase
  static inline void erase(DbLink *link, DbLink *last) noexcept {
    zltDbLinkErase(link, last);
  }

  /// @see zltDbLinkEraseUntil
  static inline void eraseUntil(DbLink *link, DbLink *end = nullptr) noexcept {
    zltDbLinkEraseUntil(link, end);
  }

  /// @see zltDbLinkPop
  static inline void pop(DbLink *link) noexcept {
    zltDbLinkPop(link);
  }
}
