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
  void *datum0;
  void *datum1;
  void *datum2;
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

typedef struct {
  const void *tree;
  size_t *dataIndex;
} zlt23TreeIter;

#define zlt23TreeIterMemb(p, m) zltMemb(p, zlt23TreeIter, m)

/// @param lr 0 lr, 2 rl
static inline zlt23TreeIter zlt23TreeIterBegin(const void *tree, int lr) {
  return (zlt23TreeIter) { .tree = zlt23TreeMostSide(tree, lr), .dataIndex = lr };
}

static inline zlt23TreeIter zlt23TreeIterLRBegin(const void *tree) {
  return zlt23TreeIterBegin(tree, 0);
}

static inline zlt23TreeIter zlt23TreeIterRLBegin(const void *tree) {
  return zlt23TreeIterBegin(tree, 2);
}

/// @return data
void *zlt23TreeIterLRNext(zlt23TreeIter *it);

/// @return data
void *zlt23TreeIterRLNext(zlt23TreeIter *it);
// iterators end

// find operations begin
typedef int zlt23TreeCmpForFind(const void *a, const void *b);

/// @return data
void *zlt23TreeFind(const void *tree, zlt23TreeCmpForFind *cmp, const void *data);

/// @param tree requires not null
/// @return insert slot
void **zlt23TreeFindForInsert(void *tree, zlt23TreeCmpForFind *cmp, const void *data);
// find operations end

void zlt23TreeAfterInsert(void **root, void *tree);
void zltRBTreeBeforeErase(void **root, void *tree);

#ifdef __cplusplus

}

#endif

#endif
