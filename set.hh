#pragma once

#include"rbtree.hh"

namespace zlt {
  template<class T>
  struct Set {
    void *root;
  };
}

namespace zlt::set {
  template<class T>
  struct Tree {
    RBTree rbTree;
    T value;
  };

  template<class T>
  static inline Tree<T> make(const void *parent, const T &value) {
    return (Tree<T>) { .rbTree = rbtree::make(parent), .value = value };
  }

  template<class T>
  static inline Tree<T> make(const void *parent, T &&value) noexcept {
    return (Tree<T>) { .rbTree = rbtree::make(parent), .value = std::move(value) };
  }

  template<class T, class Cmp>
  struct ValueCompare {
    const Cmp &cmp;
    ValueCompare(const Cmp &cmp) noexcept: cmp(cmp) {}
    template<class U>
    auto operator ()(U &&u, const void *tree) const noexcept {
      return compare(std::forward<U>(u), member(tree, &Tree<T>::value));
    }
  };
}

namespace zlt {
  template<class T, class U, class Cmp = Compare>
  static inline void *find(const Set<T> &set, U &&u, const Cmp &cmp = {}) noexcept {
    return bitree::find(set.root, set::ValueCompare<T, Cmp>(cmp), std::forward<U>(u));
  }

  template<class T, class U, class Cmp = Compare>
  static inline void *&findForInsert(void *&parent, Set<T> &set, U &&u, const Cmp &cmp = {}) noexcept {
    return *bitree::findForInsert(parent, set.root, set::ValueCompare<T, Cmp>(cmp), std::forward<U>(u));
  }

  template<class T>
  static inline void erase(Set<T> &set, void *node) noexcept {
    rbtree::erase(set.root, node);
  }

  template<class T, class U, class Cmp = Compare>
  void *findAndErase(Set<T> &set, U &&u, const Cmp &cmp = {}) noexcept {
    void *node = find(set, std::forward<U>(u), cmp);
    if (!node) {
      return nullptr;
    }
    rbtree::beforeErase(set.root, node);
    erase(set, node);
    return node;
  }
}
