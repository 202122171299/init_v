#ifndef _EZINC3_H
#define _EZINC3_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "fdtd3.h"

void ezIncInit(Grid* g);
double ezInc(double time, double location);

#endif /* matches #ifndef _EZINC2_H */
#pragma once
