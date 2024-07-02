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
  void insertAfter(DbLink *dest, DbLink *link, DbLink *last) {
    zltDbLinkInsertAfter(dest, link, last);
  }

  /// @see zltDbLinkInsertUntilAfter
  void insertUntilAfter(DbLink *dest, DbLink *link, zltDbLink *end);

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
}
