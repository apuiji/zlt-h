#ifndef ZLT_23TREE_H
#define ZLT_23TREE_H

#include"xyz.h"

#ifdef __cplusplus

extern "C" {

#endif

typedef struct {
  void *parent;
  void *lchd;
  void *mchd;
  void *rchd;
} zlt23Tree;

#define zlt23TreeMemb(p, m) zltMemb(p, zlt23Tree, m)

static inline zlt23Tree zlt23TreeMake(const void *parent) {
  return (zlt23Tree) { .parent = parent };
}



void *zlt23TreeMostSide

#ifdef __cplusplus

}

#endif

#endif
