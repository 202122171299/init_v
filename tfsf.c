#include <math.h>
#include "fdtd3.h"
#include "ezinc3.h"

static int tfsfBoundary = 0;

void tfsfInit(Grid *g) {
    printf("Enter location of TFSF boundary: ");
    scanf_s(" %d", &tfsfBoundary);

    ezIncInit(g); // 初始化源函数

    return;
}

void tfsfUpdate(Grid *g) {
    /* 检查是否已调用tfsfInit() */
    if (tfsfBoundary <= 0) {
        fprintf(stderr,
                "tfsfUpdate: tfsfInit must be called before tfsfUpdate.\n"
                " Boundary location must be set to positive value.\n");
        exit(-1);
    }
    else if (tfsfBoundary %2==0) {
        fprintf(stderr,
            "In this case, enter odd nodes\n"
            );
        exit(-1);
    }

    /* 修正TFSF边界附近的Hy */
    Hy(tfsfBoundary) -= ezInc(Time, 0.0) * Chye(tfsfBoundary);

    /* 修正TFSF边界附近的Ez */
    Ez(tfsfBoundary + 1) += ezInc(Time + 0.5, -0.5);

    return;
}


void transUpdate(Grid* g) {
    /* 检查是否已调用tfsfInit() */
    if (tfsfBoundary <= 0) {
        fprintf(stderr,
            "tfsfUpdate: tfsfInit must be called before tfsfUpdate.\n"
            " Boundary location must be set to positive value.\n");
        exit(-1);
    }

    /* 更新源电场Ez */
    Ez(tfsfBoundary) += ezInc(Time , 0.0);

    return;
}