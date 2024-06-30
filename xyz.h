#ifndef ZLT_XYZ_H
#define ZLT_XYZ_H

#include<stdbool.h>
#include<stddef.h>
#include<stdlib.h>

#include"ifcpp_begin.h"

#define zltInvSize ((size_t) -1)
#define zltInvPtr ((void *) -1)

#define zltCast(v, t) ((t) (v))

/// @param p pointer
#define zltMemberOf(p, t, m) (zltCast(p, t *)->m)

#define zltOffsetOf(t, m) ((size_t) &zltMemberOf(NULL, t, m))

/// @param p pointer
#define zltContainerOf(p, t, m) ((t *) ((char *) (p) - zltOffsetOf(t, m)))

void zltMemSwap(void *a, void *b, size_t size);

#define zltTypeAlloc(t) ((t *) malloc(sizeof(t)))
#define zltTypeAllocN(t, n) ((t *) malloc(sizeof(t) * (n)))

#include"ifcpp_end.h"

#endif
