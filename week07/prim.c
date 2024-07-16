MSTree primMST(Graph g) {
    MSTree mst = newGraph(g->nV); // empty MST
    VertexSet seen = newSet(); // vertices in MST
    EdgeSet fringe = newSet(); // edges at fringe

    // starting vertex is in our MST
    SetInclude(seen, 0);

    // add all edges from 0 to fringe
    SetInclude(fringe, edgesAt(0)); 

    Vertex curr;
    Edge e, e2;

    while (SetSize(seen) < g->nV) 

        // get cheapest edge on fringe
        e = getSmallestEdge(fringe);
        SetRemove(fringe, e);

        // we know e.v is in the MST, make sure e.w is not in the MST
        if (isElem(seen, e.w)) continue;

        // add e.w to MST
        SetInclude(seen, e.w);
        mst = insertEdge(mst, e);

        curr = e.w;
        for (e in edgesAt(curr)) {
            // add edges from w to fringe set
            if (isElem(seen, e.w)) continue;
            SetInclude(fringe, e);
        }
    }
    return mst;
}
