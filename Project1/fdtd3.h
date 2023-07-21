#ifndef _FDTD3_H
#define _FDTD3_H

#include <stdio.h>
#include <stdlib.h>

struct Grid {
    double *ez, *ceze, *cezh;
    double *hy, *chyh, *chye;
    int sizeX;
    int time, maxTime;
    double cdtds;
};

typedef struct Grid Grid;

/* 宏定义用于访问数组和其他内容 */
#define Hy(MM) g->hy[MM]
#define Chyh(MM) g->chyh[MM]
#define Chye(MM) g->chye[MM]

#define Ez(MM) g->ez[MM]
#define Ceze(MM) g->ceze[MM]
#define Cezh(MM) g->cezh[MM]

#define SizeX g->sizeX
#define Time g->time
#define MaxTime g->maxTime
#define Cdtds g->cdtds

/* 内存分配宏定义 */
#define ALLOC_1D(PNTR, NUM, TYPE) \
    PNTR = (TYPE *)calloc(NUM, sizeof(TYPE)); \
    if (!PNTR) { \
        perror("ALLOC_1D"); \
        fprintf(stderr, "Allocation failed for " #PNTR ". Terminating...\n");\
        exit(-1); \
    }

/* 函数原型 */
void abcInit(Grid *g);
void abc(Grid *g);

void gridInit3(Grid *g);

void snapshotInit(Grid *g);
void snapshot(Grid *g);

void tfsfInit(Grid *g);
void tfsfUpdate(Grid *g);

void updateE3(Grid *g);
void updateH3(Grid *g);

#endif /* matches #ifndef _FDTD3_H */
