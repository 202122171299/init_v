#include "fdtd3.h"

// ��ʼ��ABC - ����������£���������κβ�����
void abcInit(Grid* g) {

    return;
}

// Ӧ��ABC - ����������£���Ӧ�����������ࡣ
void abc(Grid* g) {

    /* �򵥵�����������ձ߽����� */
    Ez(0) = Ez(1);

    return;
}
