#ifndef ZLT_XYZ_H
#define ZLT_XYZ_H

#include<stdbool.h>
#include<stddef.h>
#include<stdlib.h>

#include"ifcpp_begin.h"

#define zltInvSize ((size_t) -1)
#define zltInvPtr ((void *) -1)

/// @param t type name
#define zltCast(v, t) ((t) (v))

/// @param p pointer
/// @param t type name
/// @param m member name
#define zltMemberOf(p, t, m) (zltCast(p, t *)->m)

/// @param t type name
/// @param m member name
#define zltOffsetOf(t, m) ((size_t) &zltMemberOf(NULL, t, m))

/// @param p pointer
/// @param t type name
/// @param m member name
#define zltContainerOf(p, t, m) ((t *) ((char *) (p) - zltOffsetOf(t, m)))

void zltMemSwap(void *a, void *b, size_t size);

/// @param t type name
#define zltTypeAlloc(t) ((t *) malloc(sizeof(t)))

/// @param t type name
/// @param n count
#define zltTypeAllocN(t, n) ((t *) malloc(sizeof(t) * (n)))

#include"ifcpp_end.h"

#endif
