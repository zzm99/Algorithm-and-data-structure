#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src, des;
};

class Graph{
public:
	int V, E;
	Edge* edge;
	Graph(int V, int E){
		this->V = V;
		this->E = E;
		this->edge = new Edge[E*sizeof(Edge)];
	}
};

struct subset{
	int parent;
	int rank;
};


int find(subset subsets[], int i){
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int isCycle(Graph* gh){
	subset* subsets = new subset[gh->V*sizeof(subset)];
	for(int i=0; i<gh->V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
	}
	for(int i=0; i<gh->E; i++){
		int xset = find(subsets, gh->edge[i].src);
		int yset = find(subsets, gh->edge[i].des);
		if(xset == yset) return 1;
		Union(subsets, xset, yset);
	}
}

int main()
{
    /* Let us create the following graph
         0
        |  \
        |    \
        1-----2 */

    int V = 3, E = 3;
    Graph* graph = new Graph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].des = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].des = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].des = 2;

    if (isCycle(graph))
        printf( "Graph contains cycle" );
    else
        printf( "Graph doesn't contain cycle" );

    return 0;
}
