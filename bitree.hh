#pragma once

#include"bitree.h"

namespace zlt {
  using BiTree = zltBiTree;
}

namespace zlt::bitree {
  static inline auto make(const BiTree *parent = nullptr) noexcept {
    return zltBiTreeMake(parent);
  }

  /// @see zltBiTreeSwap
  static inline void swap(BiTree *&root, BiTree *a, BiTree *b) noexcept {
    zltBiTreeSwap(&root, a, b);
  }

  using Dtor = zltBiTreeDtor;

  /// @see zltBiTreeClean
  static inline void clean(BiTree *tree, Dtor *dtor) noexcept {
    zltBiTreeClean(tree, dtor);
  }

  template<class Dtor>
  void clean(BiTree *tree, const Dtor &dtor) noexcept {
    if (!tree) [[unlikely]] {
      return;
    }
    auto lchd = tree->lchd;
    auto rchd = tree->rchd;
    dtor(tree);
    clean(lchd, dtor);
    clean(rchd, dtor);
  }

  template<class Dtor>
  struct CleanGuard {
    BiTree *&tree;
    Dtor dtor;
    CleanGuard(BiTree *&tree, const Dtor &dtor): tree(tree), dtor(dtor) {}
    CleanGuard(BiTree *&tree, Dtor &&dtor) noexcept: tree(tree), dtor(std::move(dtor)) {}
    ~CleanGuard() noexcept {
      clean(tree, dtor);
    }
  };

  /// @see zltBiTreeMostSide
  static inline BiTree *mostSide(const BiTree *tree, int side) noexcept {
    return zltBiTreeMostSide(tree, side);
  }

  /// @see zltBiTreeMostTop
  static inline BiTree *mostTop(const BiTree *tree) noexcept {
    return zltBiTreeMostTop(tree);
  }

  /// @see zltBiTreeMostLeft
  static inline BiTree *mostLeft(const BiTree *tree) noexcept {
    return zltBiTreeMostLeft(tree);
  }

  /// @see zltBiTreeMostRight
  static inline BiTree *mostRight(const BiTree *tree) noexcept {
    return zltBiTreeMostRight(tree);
  }

  // iterators begin
  /// @see zltBiTreeNXY
  static inline BiTree *nxy(const BiTree *tree, int xy) noexcept {
    return zltBiTreeNXY(tree, xy);
  }

  /// @see zltBiTreeNLR
  static inline BiTree *nlr(const BiTree *tree) noexcept {
    return zltBiTreeNLR(tree);
  }

  /// @see zltBiTreeNRL
  static inline BiTree *nrl(const BiTree *tree) noexcept {
    return zltBiTreeNRL(tree);
  }

  /// @see zltBiTreeXNY
  static inline BiTree *xny(const BiTree *tree, int xy) noexcept {
    return zltBiTreeXNY(tree, xy);
  }

  /// @see zltBiTreeXNYBegin
  static inline BiTree *xnyBegin(const BiTree *tree, int xy) noexcept {
    return zltBiTreeXNYBegin(tree, xy);
  }

  /// @see zltBiTreeLNR
  static inline BiTree *lnr(const BiTree *tree) noexcept {
    return zltBiTreeLNR(tree);
  }

  /// @see zltBiTreeRNL
  static inline BiTree *rnl(const BiTree *tree, int xy) noexcept {
    return zltBiTreeRNL(tree);
  }

  /// @see zltBiTreeLNRBegin
  static inline BiTree *lnrBegin(const BiTree *tree) noexcept {
    return zltBiTreeLNRBegin(tree);
  }

  /// @see zltBiTreeRNLBegin
  static inline BiTree *rnlBegin(const BiTree *tree) noexcept {
    return zltBiTreeRNLBegin(tree);
  }

  /// @see zltBiTreeXYN
  static inline BiTree *xyn(const BiTree *tree, int xy) noexcept {
    return zltBiTreeXYN(tree, xy);
  }

  /// @see zltBiTreeXYNBegin
  static inline BiTree *xynBegin(const BiTree *tree, int xy) noexcept {
    return zltBiTreeXYNBegin(tree, xy);
  }

  /// @see zltBiTreeLRN
  static inline BiTree *lrn(const BiTree *tree) noexcept {
    return zltBiTreeLRN(tree);
  }

  /// @see zltBiTreeRLN
  static inline BiTree *rln(const BiTree *tree) noexcept {
    return zltBiTreeRLN(tree);
  }

  /// @see zltBiTreeLRNBegin
  static inline BiTree *lrnBegin(const BiTree *tree) noexcept {
    return zltBiTreeLRNBegin(tree);
  }

  /// @see zltBiTreeRLNBegin
  static inline BiTree *rlnBegin(const BiTree *tree) noexcept {
    return zltBiTreeRLNBegin(tree);
  }
  // iterators end

  /// @see zltBiTreeRotate
  static inline BiTree *rotate(BiTree *tree, bool right) noexcept {
    return zltBiTreeRotate(tree, right);
  }

  /// @see zltBiTreeLRot
  static inline BiTree *lrot(BiTree *tree) noexcept {
    return zltBiTreeLRot(tree);
  }

  /// @see zltBiTreeRRot
  static inline BiTree *rrot(BiTree *tree) noexcept {
    return zltBiTreeRRot(tree);
  }

  // find operations begin
  using ComparatorForFind = zltBiTreeCmpForFind;

  /// @see zltBiTreeFind
  static inline BiTree *find(const BiTree *tree, ComparatorForFind *cmp, const void *data) noexcept {
    return zltBiTreeFind(tree, cmp, data);
  }

  /// @see zltBiTreeFindForInsert
  static inline BiTree *&findForInsert(BiTree *&parent, BiTree *&tree, ComparatorForFind *cmp, const void *data) noexcept {
    return *zltBiTreeFindForInsert(&parent, &tree, cmp, data);
  }

  template<class Cmp, class T>
  BiTree *find(const BiTree *tree, const Cmp &cmp, T &&t) noexcept {
    if (!tree) [[unlikely]] {
      return nullptr;
    }
    int diff = cmp(std::forward<T>(t), tree);
    if (!diff) {
      return (BiTree *) tree;
    }
    return find(tree->children[diff > 0], cmp, std::forward<T>(t));
  }

  template<class Cmp, class T>
  BiTree *&findForInsert(BiTree *&parent, BiTree *&tree, const Cmp &cmp, T &&t) noexcept {
    if (!tree) [[unlikely]] {
      return tree;
    }
    int diff = cmp(std::forward<T>(t), tree);
    if (!diff) {
      return tree;
    }
    parent = tree;
    return findForInsert(tree->children[diff > 0], cmp, std::forward<T>(t));
  }
  // find operations end
}
