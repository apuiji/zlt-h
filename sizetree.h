#ifndef ZLT_SIZETREE_H
#define ZLT_SIZETREE_H

#include"rbtree.h"

#include"ifcpp_begin.h"

typedef struct {
  zltRBTree rbTree;
  size_t value;
} zltSizeTree;

static inline zltSizeTree zltSizeTreeMake(const zltBiTree *parent, size_t value) {
  return (zltSizeTree) { .rbTree = zltRBTreeMake(parent), .value = value };
}

int zltSizeTreeCmpForFind(const void *value, const zltBiTree *tree);

static inline void *zltSizeTreeFind(const void *tree, size_t value) {
  return zltBiTreeFind(tree, zltSizeTreeCmpForFind, &value);
}

static inline void **zltSizeTreeFindForInsert(void **parent, void **tree, size_t value) {
  return zltBiTreeFindForInsert(parent, tree, zltSizeTreeCmpForFind, &value);
}

static inline void *zltSizeTreeFindAndErase(void **tree, size_t value) {
  return zltRBTreeFindAndErase(tree, zltSizeTreeCmpForFind, &value);
}

#include"ifcpp_end.h"

#endif
