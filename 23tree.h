#ifndef ZLT_23TREE_H
#define ZLT_23TREE_H

#include"xyz.h"

#ifdef __cplusplus

extern "C" {

#endif

typedef struct {
  void *parent;
  void *children[0];
  void *lchd;
  void *mchd;
  void *rchd;
  void *data[3];
} zlt23Tree;

#define zlt23TreeMemb(p, m) zltMemb(p, zlt23Tree, m)

// constructors begin
static inline zlt23Tree zlt23TreeMake(const void *parent) {
  return (zlt23Tree) { .parent = parent };
}

typedef void zlt23TreeDtor(void *tree);

void zlt23TreeClean(void *tree, zlt23TreeDtor *dtor);
// constructors end

// iterators begin
/// @param tree requires not null
/// @param side 0 left, 2 right
void *zlt23TreeMostSide(const void *tree, int side);

static inline void *zlt23TreeMostLeft(const void *tree) {
  return zlt23TreeMostSide(tree, 0);
}

static inline void *zlt23TreeMostRight(const void *tree) {
  return zlt23TreeMostSide(tree, 2);
}

/// @param tree requires not null
/// @param xy 0 NLR, 1 NRL
void *zlt23TreeNXY(const void *tree, int xy);

/// @param tree requires not null
/// @param xy 0
void *zlt23TreeXNY(const void *tree, int xy);

/// @param tree requires not null
/// @param xy 0 LRN, 1 RLN
void *zlt23TreeXYN(const void *tree, int xy);
// iterators end

// find operations begin
/// @return -2 goto left child, -1 found data[0], 0 goto middle child, 1 found data[1], 2 goto right child
typedef int zlt23TreeCmpForFind(const void *a, const void *b);

/// @param[out] tree found tree the data inside, requires not null, usually initialized by null
void *zlt23TreeFind(void **tree, const void *root, zlt23TreeCmpForFind *cmp, const void *data);

/// @param[out] tree found tree the data inside, requires not null, usually initialized by null
/// @return insert slot
void **zlt23TreeFindForInsert(void **tree, void *root, zlt23TreeCmpForFind *cmp, const void *data);
// find operations end

void zlt23TreeAfterInsert(void **root, void *tree);
void zltRBTreeBeforeErase(void **root, void *tree);

#ifdef __cplusplus

}

#endif

#endif
