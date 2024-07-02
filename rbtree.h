#ifndef ZLT_RBTREE_H
#define ZLT_RBTREE_H

#include<stdbool.h>
#include"bitree.h"

#include"ifcpp_begin.h"

typedef struct {
  zltBiTree biTree;
  bool red;
} zltRBTree;

// constructors and destructors begin
static inline zltRBTree zltRBTreeMake(const zltBiTree *parent) {
  return (zltRBTree) { .biTree = zltBiTreeMake(parent), .red = true };
}

/// @param a requires not null
/// @param b requires not null
void zltRBTreeSwap(zltBiTree **root, zltRBTree *a, zltRBTree *b);
// constructors and destructors end

void zltRBTreeAfterInsert(zltBiTree **root, zltRBTree *node);
void zltRBTreeBeforeErase(zltBiTree **root, zltRBTree *node);
void zltRBTreeErase(zltBiTree **root, zltRBTree *node);

/// @return erased node
zltRBTree *zltRBTreeFindAndErase(zltBiTree **root, zltBiTreeCmpForFind *cmp, const void *data);

#include"ifcpp_end.h"

#endif
