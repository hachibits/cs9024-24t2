#include "Graph.h"
#include <stdbool.h>

#define MAX_NODES 128

void   PQueueInit();
void   joinPQueue(Vertex);
Vertex leavePQueue(int[]);
bool   PQueueIsEmpty();
