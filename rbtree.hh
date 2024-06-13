#pragma once

#include"bitree.hh"
#include"rbtree.h"

namespace zlt {
  using RBTree = zltRBTree;
}

namespace zlt::rbtree {
  /// @see zltRBTreeMake
  static inline RBTree make(const void *parent) noexcept {
    return zltRBTreeMake(parent);
  }

  /// @see zltRBTreeSwap
  static inline void swap(void *&root, void *a, void *b) noexcept {
    zltRBTreeSwap(&root, a, b);
  }

  /// @see zltRBTreeAfterInsert
  static inline void afterInsert(void *&root, void *node) noexcept {
    zltRBTreeAfterInsert(&root, node);
  }

  /// @see zltRBTreeBeforeErase
  static inline void beforeErase(void *&root, void *node) noexcept {
    zltRBTreeBeforeErase(&root, node);
  }

  /// @see zltRBTreeErase
  static inline void erase(void *&root, void *node) noexcept {
    return zltRBTreeErase(&root, node);
  }

  /// @see zltRBTreeFindAndErase
  static inline void *findAndErase(void *&tree, bitree::ComparatorForFind *cmp, const void *data) noexcept {
    return zltRBTreeFindAndErase(&tree, cmp, data);
  }

  /// @see zltRBTreeFindAndErase
  template<class Cmp, class T>
  void *findAndErase(void *&root, const Cmp &cmp, T &&t) noexcept {
    void *node = bitree::find(root, cmp, std::forward<T>(t));
    if (!node) {
      return nullptr;
    }
    beforeErase(root, node);
    erase(root, node);
    return node;
  }
}
