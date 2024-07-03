#pragma once

#include"rbtree.hh"

namespace zlt {
  template<class T>
  struct Set {
    BiTree *root;
  };
}

namespace zlt::set {
  template<class T>
  struct Tree {
    RBTree rbTree;
    T value;
  };

  template<class T>
  static inline Tree<T> make(const BiTree *parent = nullptr, const T &value = {}) {
    return (Tree<T>) { .rbTree = rbtree::make(parent), .value = value };
  }

  template<class T, class Cmp>
  struct ValueCompare {
    const Cmp &compare;
    ValueCompare(const Cmp &compare) noexcept: compare(compare) {}
    template<class U>
    auto operator ()(U &&u, const BiTree *tree) const noexcept {
      return compare(std::forward<U>(u), memberOf(tree, &Tree<T>::value));
    }
  };
}

namespace zlt {
  template<class T, class U, class Cmp = Compare>
  static inline set::Tree<T> *find(const Set<T> &set, U &&u, const Cmp &cmp = {}) noexcept {
    return (set::Tree<T> *) bitree::find(set.root, set::ValueCompare<T, Cmp>(cmp), std::forward<U>(u));
  }

  template<class T, class U, class Cmp = Compare>
  static inline BiTree *&findForInsert(BiTree *&parent, Set<T> &set, U &&u, const Cmp &cmp = {}) noexcept {
    return bitree::findForInsert(parent, set.root, set::ValueCompare<T, Cmp>(cmp), std::forward<U>(u));
  }

  template<class T>
  static inline void erase(Set<T> &set, set::Tree<T> *node) noexcept {
    rbtree::erase(set.root, (RBTree *) node);
  }

  template<class T, class U, class Cmp = Compare>
  set::Tree<T> *findAndErase(Set<T> &set, U &&u, const Cmp &cmp = {}) noexcept {
    auto node = find(set, std::forward<U>(u), cmp);
    if (!node) {
      return nullptr;
    }
    rbtree::beforeErase(set.root, (RBTree *) node);
    erase(set, node);
    return node;
  }
}
