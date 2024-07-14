#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "PQueue.h"

void relax(int u, int v, int weight, int dist[], int pred[]) {
    if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pred[v] = u;
    }
}

void dijkstraSSSP(Graph g, Vertex source) {
   int  dist[MAX_NODES];
   int  pred[MAX_NODES];
   bool vSet[MAX_NODES];
   int s;

   PQueueInit();
   int nV = numOfVertices(g);
   for (s = 0; s < nV; s++) {
      joinPQueue(s);
      dist[s] = LONG_MAX;
      pred[s] = -1;
      vSet[s] = true;
   }
   dist[source] = 0;

   while (!PQueueIsEmpty()) {
    int u = leavePQueue(dist);
    vSet[u] = false;

    for (int v = 0; v < nV; v++) {
      if (vSet[v]) {
        int weight = adjacent(g, u, v);
        if (weight != -1 && dist[u] + weight < dist[v]) {
          dist[v] = dist[u] + weight;
          pred[v] = u;
        }
      }
    }
  }

  for (int i = 0; i < nV; i++) {
    printf("%d: distance = %d, shortest path: ", i, dist[i]);
    int vertex = i;
    while (vertex != source) {
      printf("%d-", vertex);
      vertex = pred[vertex];
    }
    printf("%d\n", source);
  }

}

void reverseEdge(Edge *e) {
   Vertex temp = e->v;
   e->v = e->w;
   e->w = temp;
}
