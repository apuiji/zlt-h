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

static inline zltSizeTree *zltSizeTreeFind(const zltBiTree *tree, size_t value) {
  return (zltSizeTree *) zltBiTreeFind(tree, zltSizeTreeCmpForFind, &value);
}

static inline zltBiTree **zltSizeTreeFindForInsert(zltBiTree **parent, zltBiTree **tree, size_t value) {
  return zltBiTreeFindForInsert(parent, tree, zltSizeTreeCmpForFind, &value);
}

static inline zltSizeTree *zltSizeTreeFindAndErase(zltBiTree **root, size_t value) {
  return (zltSizeTree *) zltRBTreeFindAndErase(root, zltSizeTreeCmpForFind, &value);
}

#include"ifcpp_end.h"

#endif
