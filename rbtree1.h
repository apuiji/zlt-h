#ifndef ZLT_RBTREE1_H
#define ZLT_RBTREE1_H

#include<stddef.h>
#include"rbtree.h"
#include"string.h"

#include"ifcpp_begin.h"

// double tree begin
typedef struct {
  zltRBTree rbTree;
  double value;
} zltDoubleTree;

static inline zltDoubleTree zltDoubleTreeMake(const zltBiTree *parent, double value) {
  return (zltDoubleTree) { .rbTree = zltRBTreeMake(parent), .value = value };
}

int zltDoubleTreeCmpForFind(const void *value, const zltBiTree *tree);

static inline zltDoubleTree *zltDoubleTreeFind(const zltBiTree *tree, double value) {
  return (zltDoubleTree *) zltBiTreeFind(tree, zltDoubleTreeCmpForFind, &value);
}

static inline zltBiTree **zltDoubleTreeFindForInsert(zltBiTree **parent, zltBiTree **tree, double value) {
  return zltBiTreeFindForInsert(parent, tree, zltDoubleTreeCmpForFind, &value);
}

static inline zltDoubleTree *zltDoubleTreeFindAndErase(zltBiTree **root, double value) {
  return (zltDoubleTree *) zltRBTreeFindAndErase(root, zltDoubleTreeCmpForFind, &value);
}
// double tree end

// pointer tree begin
typedef struct {
  zltRBTree rbTree;
  void *value;
} zltPtrTree;

static inline zltPtrTree zltPtrTreeMake(const zltBiTree *parent, void *value) {
  return (zltPtrTree) { .rbTree = zltRBTreeMake(parent), .value = value };
}

int zltPtrTreeCmpForFind(const void *value, const zltBiTree *tree);

static inline zltPtrTree *zltPtrTreeFind(const zltBiTree *tree, void *value) {
  return (zltPtrTree *) zltBiTreeFind(tree, zltPtrTreeCmpForFind, value);
}

static inline zltBiTree **zltPtrTreeFindForInsert(zltBiTree **parent, zltBiTree **tree, void *value) {
  return zltBiTreeFindForInsert(parent, tree, zltPtrTreeCmpForFind, value);
}

static inline zltPtrTree *zltPtrTreeFindAndErase(zltBiTree **root, void *value) {
  return (zltPtrTree *) zltRBTreeFindAndErase(root, zltPtrTreeCmpForFind, value);
}
// pointer tree end

// size tree begin
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
// size tree end

// string tree begin
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
// string tree end

#include"ifcpp_end.h"

#endif
