#ifndef ZLT_STRTREE_H
#define ZLT_STRTREE_H

#include"rbtree.h"
#include"string.h"

#include"ifcpp_begin.h"

typedef struct {
  zltRBTree rbTree;
  zltString value;
} zltStrTree;

static inline zltStrTree zltStrTreeMake(const zltBiTree *parent, zltString value) {
  return (zltStrTree) { .rbTree = zltRBTreeMake(parent), .value = value };
}

int zltStrTreeCmpForFind(const void *data, const zltBiTree *tree);

static inline zltStrTree *zltStrTreeFind(const zltBiTree *tree, zltString value) {
  return (zltStrTree *) zltBiTreeFind(tree, zltStrTreeCmpForFind, &value);
}

static inline zltBiTree **zltStrTreeFindForInsert(zltBiTree **parent, zltBiTree **tree, zltString value) {
  return zltBiTreeFindForInsert(parent, tree, zltStrTreeCmpForFind, &value);
}

/// @return erased node
static inline zltStrTree *zltStrTreeFindAndErase(zltBiTree **root, zltString value) {
  return (zltStrTree *) zltRBTreeFindAndErase(root, zltStrTreeCmpForFind, &value);
}

#include"ifcpp_end.h"

#endif
