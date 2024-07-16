#include <stdio.h>
#include <stdlib.h>

int *visited;  // array of booleans, indexed by vertex 0..V-1

typedef struct graphRep {
    int nV;
    int nE;
    int **edges;
} GraphRep;

typedef GraphRep *Graph;
typedef Graph MSTree;

typedef struct {
    Vertex v;
    Vertex w;
    int weight;
} Edge;

MSTree kruskalFindMST(Graph g) {
    MSTree mst = newGraph();  // MST initially empty
    Edge eList[g->nV];
    edges(eList, g->nE, g);
    sortEdgeList(eList, g->nE); // consider edges in increasing weight order
    for (int i = 0; mst->nE < g->nV - 1; i++) {
        Edge e = eList[i];
        insertE(mst, e); // add edge to MST
        if (hasCycle(mst))
            removeE(mst, e); // remove edge if it forms a cycle
    }
    return mst;
}

int hasCycle(Graph g) {
    visited = calloc(g->nV, sizeof(int));
    return dfsCycleCheck(g, 0, -1);
}

int dfsCycleCheck(Graph g, Vertex v, Vertex prev) {
    visited[v] = 1;
    Vertex w;
    for (w = 0; w < g->nV; w++) {
        if (g->edges[v][w] && visited[w] && w != prev) {
            return 1; // found cycle
        }
        if (g->edges[v][w] && !visited[w]) {
            if (dfsCycleCheck(g, w, v)) {
                return 1;
            }
        }
    }
    return 0; // no cycle at v
}
