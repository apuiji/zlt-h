#ifndef ZLT_RBTREE_H
#define ZLT_RBTREE_H

#include"bitree.h"

#include"ifcpp_begin.hh"

typedef struct {
  zltBiTree biTree;
  bool red;
} zltRBTree;

#define zltRBTreeMemb(p, m) zltMemb(p, zltRBTree, m)

// constructors and destructors begin
static inline zltRBTree zltRBTreeMake(const void *parent) {
  return (zltRBTree) { .biTree = zltBiTreeMake(parent), .red = true };
}

/// @param a requires not null
/// @param b requires not null
void zltRBTreeSwap(void **root, void *a, void *b);
// constructors and destructors end

void zltRBTreeAfterInsert(void **root, void *node);
void zltRBTreeBeforeErase(void **root, void *node);
void zltRBTreeErase(void **root, void *node);

/// @return erased node
void *zltRBTreeFindAndErase(void **root, zltBiTreeCmpForFind *cmp, const void *data);

#include"ifcpp_end.hh"

#endif
