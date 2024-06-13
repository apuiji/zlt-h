#pragma once

#include"bitree.h"
#include"xyz.hh"

namespace zlt {
  using BiTree = zltBiTree;
}

namespace zlt::bitree {
  static inline auto make(const void *parent) noexcept {
    return zltBiTreeMake(parent);
  }

  /// @see zltBiTreeSwap
  static inline void swap(void *&root, void *a, void *b) noexcept {
    zltBiTreeSwap(&root, a, b);
  }

  using Dtor = zltBiTreeDtor;

  /// @see zltBiTreeClean
  static inline void clean(void *tree, Dtor *dtor) noexcept {
    zltBiTreeClean(tree, dtor);
  }

  template<class Dtor>
  void clean(void *tree, const Dtor &dtor) noexcept {
    if (!tree) [[unlikely]] {
      return;
    }
    auto lchd = memberOf(tree, &BiTree::lchd);
    auto rchd = memberOf(tree, &BiTree::rchd);
    dtor(tree);
    clean(lchd, dtor);
    clean(rchd, dtor);
  }

  /// @see zltBiTreeMostSide
  static inline void *mostSide(const void *tree, int side) noexcept {
    return zltBiTreeMostSide(tree, side);
  }

  /// @see zltBiTreeMostTop
  static inline void *mostTop(const void *tree) noexcept {
    return zltBiTreeMostTop(tree);
  }

  /// @see zltBiTreeMostLeft
  static inline void *mostLeft(const void *tree) noexcept {
    return zltBiTreeMostLeft(tree);
  }

  /// @see zltBiTreeMostRight
  static inline void *mostRight(const void *tree) noexcept {
    return zltBiTreeMostRight(tree);
  }

  // iterators begin
  /// @see zltBiTreeNXY
  static inline void *nxy(const void *tree, int xy) noexcept {
    return zltBiTreeNXY(tree, xy);
  }

  /// @see zltBiTreeNLR
  static inline void *nlr(const void *tree) noexcept {
    return zltBiTreeNLR(tree);
  }

  /// @see zltBiTreeNRL
  static inline void *nrl(const void *tree) noexcept {
    return zltBiTreeNRL(tree);
  }

  /// @see zltBiTreeXNY
  static inline void *xny(const void *tree, int xy) noexcept {
    return zltBiTreeXNY(tree, xy);
  }

  /// @see zltBiTreeXNYBegin
  static inline void *xnyBegin(const void *tree, int xy) noexcept {
    return zltBiTreeXNYBegin(tree, xy);
  }

  /// @see zltBiTreeLNR
  static inline void *lnr(const void *tree) noexcept {
    return zltBiTreeLNR(tree);
  }

  /// @see zltBiTreeRNL
  static inline void *rnl(const void *tree, int xy) noexcept {
    return zltBiTreeRNL(tree);
  }

  /// @see zltBiTreeLNRBegin
  static inline void *lnrBegin(const void *tree) noexcept {
    return zltBiTreeLNRBegin(tree);
  }

  /// @see zltBiTreeRNLBegin
  static inline void *rnlBegin(const void *tree) noexcept {
    return zltBiTreeRNLBegin(tree);
  }

  /// @see zltBiTreeXYN
  static inline void *xyn(const void *tree, int xy) noexcept {
    return zltBiTreeXYN(tree, xy);
  }

  /// @see zltBiTreeXYNBegin
  static inline void *xynBegin(const void *tree, int xy) noexcept {
    return zltBiTreeXYNBegin(tree, xy);
  }

  /// @see zltBiTreeLRN
  static inline void *lrn(const void *tree) noexcept {
    return zltBiTreeLRN(tree);
  }

  /// @see zltBiTreeRLN
  static inline void *rln(const void *tree) noexcept {
    return zltBiTreeRLN(tree);
  }

  /// @see zltBiTreeLRNBegin
  static inline void *lrnBegin(const void *tree) noexcept {
    return zltBiTreeLRNBegin(tree);
  }

  /// @see zltBiTreeRLNBegin
  static inline void *rlnBegin(const void *tree) noexcept {
    return zltBiTreeRLNBegin(tree);
  }
  // iterators end

  /// @see zltBiTreeRotate
  static inline void *rotate(void *tree, bool right) noexcept {
    return zltBiTreeRotate(tree, right);
  }

  /// @see zltBiTreeLRot
  static inline void *lrot(void *tree) noexcept {
    return zltBiTreeLRot(tree);
  }

  /// @see zltBiTreeRRot
  static inline void *rrot(void *tree) noexcept {
    return zltBiTreeRRot(tree);
  }

  // find operations begin
  using ComparatorForFind = zltBiTreeCmpForFind;

  /// @see zltBiTreeFind
  static inline void *find(const void *tree, ComparatorForFind *cmp, const void *data) noexcept {
    return zltBiTreeFind(tree, cmp, data);
  }

  /// @see zltBiTreeFindForInsert
  static inline void *&findForInsert(void *&parent, void *&tree, ComparatorForFind *cmp, const void *data) noexcept {
    return *zltBiTreeFindForInsert(&parent, &tree, cmp, data);
  }

  template<class Cmp, class T>
  void *find(const void *tree, const Cmp &cmp, T &&t) noexcept {
    if (!tree) [[unlikely]] {
      return nullptr;
    }
    int diff = cmp(std::forward<T>(t), tree);
    if (!diff) {
      return (void *) tree;
    }
    return find(memberOf(tree, &BiTree::children)[diff > 0], cmp, std::forward<T>(t));
  }

  template<class Cmp, class T>
  void *&findForInsert(void *&parent, void *&tree, const Cmp &cmp, T &&t) noexcept {
    if (!tree) [[unlikely]] {
      return tree;
    }
    int diff = cmp(std::forward<T>(t), tree);
    if (!diff) {
      return tree;
    }
    parent = tree;
    return findForInsert(memberOf(tree, &BiTree::children)[diff > 0], cmp, std::forward<T>(t));
  }
  // find operations end
}
