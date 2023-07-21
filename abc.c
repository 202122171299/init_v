#include "fdtd3.h"

// 初始化ABC - 在这种情况下，无需进行任何操作。
void abcInit(Grid* g) {

    return;
}

// 应用ABC - 在这种情况下，仅应用于网格的左侧。
void abc(Grid* g) {

    /* 简单的左侧网格吸收边界条件 */
    Ez(0) = Ez(1);

    return;
}
