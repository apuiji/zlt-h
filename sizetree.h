#ifndef ZLT_SIZETREE_H
#define ZLT_SIZETREE_H

#include"rbtree.h"

#ifdef __cplusplus

extern "C" {

#endif

typedef struct {
  zltRBTree rbTree;
  size_t value;
} zltSizeTree;

#define zltSizeTreeMemb(p, m) zltMemb(p, zltSizeTree, m)

static inline zltSizeTree zltSizeTreeMake(const void *parent, size_t value) {
  return (zltSizeTree) { .rbTree = zltRBTreeMake(parent), .value = value };
}

int zltSizeTreeCmpForFind(size_t data, const void *tree);

static inline void *zltSizeTreeFind(const void *tree, size_t value) {
  return zltBiTreeFind(tree, zltSizeTreeCmpForFind, value);
}

static inline void **zltSizeTreeFindForInsert(void **parent, void **tree, size_t value) {
  return zltBiTreeFindForInsert(parent, tree, zltSizeTreeCmpForFind, value);
}

#ifdef __cplusplus

}

#endif

#endif
