#pragma once

#include"rbtree.hh"

namespace zlt {
  template<class K, class T>
  struct Map {
    BiTree *root;
  };
}

namespace zlt::map {
  template<class K, class T>
  struct Tree {
    RBTree rbTree;
    K key;
    T value;
  };

  template<class K, class T>
  static inline Tree<K, T> make(const BiTree *parent, const K &key = {}, const T &value = {}) {
    return (Tree<K, T>) { .rbTree = rbtree::make(parent), .key = key, .value = value };
  }

  template<class K, class T, class Cmp>
  struct KeyCompare {
    const Cmp &compare;
    KeyCompare(const Cmp &compare) noexcept: compare(compare) {}
    template<class U>
    auto operator ()(U &&u, const BiTree *tree) const noexcept {
      return compare(std::forward<U>(u), memberOf(tree, &Tree<K, T>::key));
    }
  };
}

namespace zlt {
  template<class K, class T, class U, class Cmp = Compare>
  static inline map::Tree<K, T> *find(const Map<K, T> &map, U &&u, const Cmp &cmp = {}) noexcept {
    return (map::Tree<K, T> *) rbtree::find(map.root, map::KeyCompare<K, T, Cmp>(cmp), std::forward<U>(u));
  }

  template<class K, class T, class U, class Cmp = Compare>
  static inline BiTree *&findForInsert(BiTree *&parent, Map<K, T> &map, U &&u, const Cmp &cmp = {}) noexcept {
    return rbtree::findForInsert(parent, map.root, map::KeyCompare<K, T, Cmp>(cmp), std::forward<U>(u));
  }

  template<class K, class T>
  static inline void erase(Map<K, T> &map, map::Tree<K, T> *node) noexcept {
    rbtree::erase(map.root, (RBTree *) node);
  }

  template<class K, class T, class U, class Cmp = Compare>
  map::Tree<K, T> *findAndErase(Map<K, T> &map, U &&u, const Cmp &cmp = {}) noexcept {
    auto node = find(map, std::forward<U>(u), cmp);
    if (!node) {
      return nullptr;
    }
    rbtree::beforeErase(map.root, (RBTree *) node);
    erase(map, node);
    return node;
  }
}
