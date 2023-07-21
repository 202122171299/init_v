#include "ezinc3.h"

/* 全局变量 - 但是只在本文件中可见 */
static double delay, width = 0, cdtds;

/* 提示用户输入源函数的宽度和延迟 */
void ezIncInit(Grid *g) {
    cdtds = Cdtds;
    printf("Enter delay: ");
    scanf_s(" %lf", &delay);
    printf("Enter width: ");
    scanf_s(" %lf", &width);

    return;
}

/* 计算给定时间和位置的源函数值 */
double ezInc(double time, double location) {
    if (width <= 0) {
        fprintf(stderr,
                "ezInc: must call ezIncInit before ezInc.\n"
                " Width must be positive.\n");
        exit(-1);
    }
    return exp(-pow((time - delay - location / cdtds) / width, 2));
}
