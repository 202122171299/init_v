#include "fdtd3.h"

static int temporalStride = 0, spatialStride, startTime,
startNode, endNode, frame = 0;
static char basename[80];

void snapshotInit(Grid *g) {
    printf("For the snapshots:\n");
    printf(" Duration of simulation is %d steps.\n", MaxTime);
    printf(" Enter start time and temporal stride: ");
    scanf_s(" %d %d", &startTime, &temporalStride);
    printf(" Grid has %d total nodes (ranging from 0 to %d).\n",
           SizeX, SizeX-1);
    printf(" Enter first node, last node, and spatial stride: ");
    scanf_s(" %d %d %d", &startNode, &endNode, &spatialStride);
    printf(" Enter the base name: ");
    scanf_s(" %s", basename);

    return;
}

void snapshot(Grid *g) {
    int mm;
    char filename[100];
    FILE *snapshot;

    /* 确保时间步进设置为合理的值 */
    if (temporalStride <= 0) {
        fprintf(stderr,
                "snapshot: snapshotInit must be called before snapshot.\n"
                " Temporal stride must be set to positive value.\n");
        exit(-1);
    }
    //printf("%d", Time);
    /* 满足时间条件时进行快照 */
    if (Time >= startTime &&
        (Time - startTime) % temporalStride == 0) {
        //printf("basename: %s, frame: %d\n", basename, frame);
        sprintf_s(filename, sizeof(filename), "D:\\self\\zhikezhisuan\\code\\fdtd\\sim\\%s.%d",basename,frame++);
        //sprintf_s(filename,"%s.%d",basename, frame);
        
        errno_t err = fopen_s(&snapshot,filename, "w");
        for (mm = startNode; mm <= endNode; mm += spatialStride)
            fprintf(snapshot, "%g\n", Ez(mm));
        fclose(snapshot);
    }

    return;
}
