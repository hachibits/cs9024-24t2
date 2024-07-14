#include "PQueue.h"
#include <assert.h>
#include <limits.h>

typedef struct {
   Vertex item[MAX_NODES];
   int length;
} PQueueT;

static PQueueT PQueue;

void PQueueInit() {
   PQueue.length = 0;
}

void joinPQueue(int v) {
   assert(PQueue.length < MAX_NODES);
   int i = 0;
   while (i < PQueue.length && PQueue.item[i] != v)
      i++;
   if (i == PQueue.length) {
      PQueue.item[PQueue.length] = v;
      PQueue.length++;
   }
}

Vertex leavePQueue(int priority[]) {
   assert(PQueue.length > 0);

   int i, bestIndex = 0, bestVertex = PQueue.item[0], bestWeight = LONG_MAX;
   for (i = 0; i < PQueue.length; i++) {
      if (priority[PQueue.item[i]] < bestWeight) {
         bestIndex = i;
         bestWeight = priority[PQueue.item[i]];
	 bestVertex = PQueue.item[i];
      }
   }
   PQueue.length--;
   PQueue.item[bestIndex] = PQueue.item[PQueue.length];
   return bestVertex;
}

bool PQueueIsEmpty() {
   return (PQueue.length == 0);
}
