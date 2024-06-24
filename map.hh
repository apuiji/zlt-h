#pragma once

#include"rbtree.hh"

namespace zlt {
  template<class K, class T>
  struct Map {
    void *root;
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
  static inline Tree<K, T> make(const void *parent, const K &key, T &&value = {}) {
    return (Tree<K, T>) { .rbTree = rbtree::make(parent), .key = key, .value = std::move(value) };
  }

  template<class K, class T>
  static inline Tree<K, T> make(const void *parent, K &&key, T &&value = {}) {
    return (Tree<K, T>) { .rbTree = rbtree::make(parent), .key = key, .value = std::move(value) };
  }

  template<class K, class T, class Cmp>
  struct KeyCompare {
    const Cmp &cmp;
    KeyCompare(const Cmp &cmp) noexcept: cmp(cmp) {}
    template<class U>
    auto operator ()(U &&u, const void *tree) const noexcept {
      return cmp(std::forward<U>(u), member(tree, &Tree<K, T>::key));
    }
  };
}

namespace zlt {
  template<class K, class T, class U, class Cmp = Compare>
  static inline map::Tree<K, T> *find(const Map<K, T> &map, U &&u, const Cmp &cmp = {}) noexcept {
    return (map::Tree<K, T> *) rbtree::find(map.root, map::KeyCompare<K, T>(cmp), std::forward<U>(u));
  }

  template<class K, class T, class U, class Cmp = Compare>
  static inline map::Tree<K, T> *&findForInsert(void *&parent, Map<K, T> &map, U &&u, const Cmp &cmp = {}) noexcept {
    void **a = rbtree::findForInsert(parent, map.root, map::KeyCompare<K, T>(cmp), std::forward<U>(u));
    return pointTo<map::Tree<K, T> *>(a);
  }

  template<class K, class T>
  static inline void erase(Map<K, T> &map, void *node) noexcept {
    rbtree::erase(map.root, node);
  }

  template<class K, class T, class U, class Cmp = Compare>
  map::Tree<K, T> *findAndErase(Map<K, T> &map, U &&u, const Cmp &cmp = {}) noexcept {
    auto node = find(map, std::forward<U>(u), cmp);
    if (!node) {
      return nullptr;
    }
    rbtree::beforeErase(map.root, node);
    erase(map, node);
    return node;
  }
}
