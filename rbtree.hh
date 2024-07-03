#pragma once

#include"bitree.hh"
#include"rbtree.h"

namespace zlt {
  using RBTree = zltRBTree;
}

namespace zlt::rbtree {
  /// @see zltRBTreeMake
  static inline RBTree make(const BiTree *parent) noexcept {
    return zltRBTreeMake(parent);
  }

  /// @see zltRBTreeSwap
  static inline void swap(BiTree *&root, RBTree *a, RBTree *b) noexcept {
    zltRBTreeSwap(&root, a, b);
  }

  /// @see zltRBTreeAfterInsert
  static inline void afterInsert(BiTree *&root, RBTree *node) noexcept {
    zltRBTreeAfterInsert(&root, node);
  }

  /// @see zltRBTreeBeforeErase
  static inline void beforeErase(BiTree *&root, RBTree *node) noexcept {
    zltRBTreeBeforeErase(&root, node);
  }

  /// @see zltRBTreeErase
  static inline void erase(BiTree *&root, RBTree *node) noexcept {
    return zltRBTreeErase(&root, node);
  }

  /// @see zltRBTreeFindAndErase
  static inline RBTree *findAndErase(BiTree *&root, bitree::ComparatorForFind *cmp, const void *data) noexcept {
    return zltRBTreeFindAndErase(&root, cmp, data);
  }

  /// @see zltRBTreeFindAndErase
  template<class Cmp, class T>
  RBTree *findAndErase(BiTree *&root, const Cmp &cmp, T &&t) noexcept {
    BiTree *node = bitree::find(root, cmp, std::forward<T>(t));
    if (!node) {
      return nullptr;
    }
    beforeErase(root, (zltRBTree *) node);
    erase(root, (zltRBTree *) node);
    return (zltRBTree *) node;
  }
}
