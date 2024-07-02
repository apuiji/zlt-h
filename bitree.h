#ifndef ZLT_BITREE_H
#define ZLT_BITREE_H

#include<stdbool.h>

#include"ifcpp_begin.h"

typedef struct zltBiTree zltBiTree;

struct zltBiTree {
  zltBiTree *parent;
  zltBiTree *children[0];
  zltBiTree *lchd;
  zltBiTree *rchd;
};

// constructors and destructors begin
static inline zltBiTree zltBiTreeMake(const zltBiTree *parent) {
  return (zltBiTree) { .parent = parent };
}

/// @param a requires not null
/// @param b requires not null
void zltBiTreeSwap(zltBiTree **root, zltBiTree *a, zltBiTree *b);

typedef void zltBiTreeDtor(void *tree);

void zltBiTreeClean(zltBiTree *tree, zltBiTreeDtor *dtor);
// constructors and destructors end

// iterators begin
/// @param tree requires not null
/// @param side -1 top, 0 left, 1 right
zltBiTree *zltBiTreeMostSide(const zltBiTree *tree, int side);

static inline zltBiTree *zltBiTreeMostTop(const zltBiTree *tree) {
  return zltBiTreeMostSide(tree, -1);
}

static inline zltBiTree *zltBiTreeMostLeft(const zltBiTree *tree) {
  return zltBiTreeMostSide(tree, 0);
}

static inline zltBiTree *zltBiTreeMostRight(const zltBiTree *tree) {
  return zltBiTreeMostSide(tree, 1);
}

/// @param tree requires not null
/// @param xy 0 NLR, 1 NRL
zltBiTree *zltBiTreeNXY(const zltBiTree *tree, int xy);

static inline zltBiTree *zltBiTreeNLR(const zltBiTree *tree) {
  return zltBiTreeNXY(tree, 0);
}

static inline zltBiTree *zltBiTreeNRL(const zltBiTree *tree) {
  return zltBiTreeNXY(tree, 1);
}

/// @param tree requires not null
/// @param xy 0 LNR, 1 RNL
zltBiTree *zltBiTreeXNY(const zltBiTree *tree, int xy);

static inline zltBiTree *zltBiTreeXNYBegin(const zltBiTree *tree, int xy) {
  return zltBiTreeMostSide(tree, xy);
}

static inline zltBiTree *zltBiTreeLNR(const zltBiTree *tree) {
  return zltBiTreeXNY(tree, 0);
}

static inline zltBiTree *zltBiTreeRNL(const zltBiTree *tree) {
  return zltBiTreeXNY(tree, 1);
}

static inline zltBiTree *zltBiTreeLNRBegin(const zltBiTree *tree) {
  return zltBiTreeXNYBegin(tree, 0);
}

static inline zltBiTree *zltBiTreeRNLBegin(const zltBiTree *tree) {
  return zltBiTreeXNYBegin(tree, 1);
}

/// @param tree requires not null
/// @param xy 0 LRN, 1 RLN
zltBiTree *zltBiTreeXYN(const zltBiTree *tree, int xy);

static inline zltBiTree *zltBiTreeXYNBegin(const zltBiTree *tree, int xy) {
  return zltBiTreeMostSide(tree, xy);
}

static inline zltBiTree *zltBiTreeLRN(const zltBiTree *tree) {
  return zltBiTreeXYN(tree, 0);
}

static inline zltBiTree *zltBiTreeRLN(const zltBiTree *tree) {
  return zltBiTreeXYN(tree, 1);
}

static inline zltBiTree *zltBiTreeLRNBegin(const zltBiTree *tree) {
  return zltBiTreeXYNBegin(tree, 0);
}

static inline zltBiTree *zltBiTreeRLNBegin(const zltBiTree *tree) {
  return zltBiTreeXYNBegin(tree, 1);
}
// iterators end

/// @param tree requires not null and has child on side rightabout rotation
zltBiTree *zltBiTreeRotate(zltBiTree *tree, bool right);

static inline zltBiTree *zltBiTreeLRot(zltBiTree *tree) {
  return zltBiTreeRotate(tree, false);
}

static inline zltBiTree *zltBiTreeRRot(zltBiTree *tree) {
  return zltBiTreeRotate(tree, true);
}

// find operations begin
typedef int zltBiTreeCmpForFind(const void *data, const zltBiTree *tree);

zltBiTree *zltBiTreeFind(const zltBiTree *tree, zltBiTreeCmpForFind *cmp, const void *data);

/// @param[out] parent parent node of inserted, requires not null, usually initialized by null
/// @return insert slot
zltBiTree **zltBiTreeFindForInsert(zltBiTree **parent, zltBiTree **tree, zltBiTreeCmpForFind *cmp, const void *data);
// find operations end

#include"ifcpp_end.h"

#endif
