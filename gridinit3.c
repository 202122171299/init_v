#include "fdtd3.h"

#define LOSS 0.02
#define LOSS_LAYER 180 // 损耗层开始的节点
#define EPSR 9.0

void gridInit3(Grid *g) {
    double imp0 = 377.0;
    int mm;

    SizeX = 200; // 域的尺寸
    MaxTime = 450; // 模拟的持续时间
    Cdtds = 1.0; // Courant数

    ALLOC_1D(g->ez, SizeX, double);
    ALLOC_1D(g->ceze, SizeX, double);
    ALLOC_1D(g->cezh, SizeX, double);
    ALLOC_1D(g->hy, SizeX - 1, double);
    ALLOC_1D(g->chyh, SizeX - 1, double);
    ALLOC_1D(g->chye, SizeX - 1, double);

    /* 设置电场更新系数 */
    for (mm = 0; mm < SizeX; mm++) {
        if (mm < 100) {
            Ceze(mm) = 1.0;
            Cezh(mm) = imp0;
        } else if (100<mm < LOSS_LAYER) {
            Ceze(mm) = 1.0;
            Cezh(mm) = imp0 / EPSR;
        } else {
            Ceze(mm) = (1.0 - LOSS) / (1.0 + LOSS);
            Cezh(mm) = imp0 / EPSR / (1.0 + LOSS);
        }
    }

    /* 设置磁场更新系数 */
    for (mm = 0; mm < SizeX - 1; mm++) {
        if (mm < LOSS_LAYER) {
            Chyh(mm) = 1.0;
            Chye(mm) = 1.0 / imp0;
        } else {
            Chyh(mm) = (1.0 - LOSS) / (1.0 + LOSS);
            Chye(mm) = 1.0 / imp0 / (1.0 + LOSS);
        }
    }

    return;
}
