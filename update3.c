#include "fdtd3.h"

/* 更新磁场 */
void updateH3(Grid *g) {
    int mm;

    for (mm = 0; mm < SizeX - 1; mm++) {
        Hy(mm) = Chyh(mm) * Hy(mm) +
                 Chye(mm) * (Ez(mm + 1) - Ez(mm));
    }

    return;
}

/* 更新电场 */
void updateE3(Grid *g) {
    int mm;

    for (mm = 1; mm < SizeX - 1; mm++) {
        Ez(mm) = Ceze(mm) * Ez(mm) +
                 Cezh(mm) * (Hy(mm) - Hy(mm - 1));
    }

    return;
}
