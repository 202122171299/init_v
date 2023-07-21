#include "fdtd3.h"

int main()
{
    Grid *g;

    ALLOC_1D(g, 1, Grid); // 分配Grid结构体的内存

    gridInit3(g); // 初始化网格
    abcInit(g); // 初始化ABC
    tfsfInit(g); // 初始化TFSF边界
    snapshotInit(g); // 初始化快照

    /* 时间步进 */
    for (Time = 0; Time < MaxTime; Time++) {
        
        updateH3(g); // 更新磁场
        tfsfUpdate(g); // 修正TFSF边界上的场
        abc(g); // 应用ABC
        updateE3(g); // 更新电场
        //transUpdate(g); //单纯的源
        snapshot(g); // 拍摄快照（如果适用）
    } // 时间步进结束

    return 0;
}
