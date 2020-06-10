#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src;
	int des;
};

class Graph{
public:
	int V, E;
	Edge* edge;
	Graph(int V, int E){
		this->V = V;
		this->E = E;
		this->edge = new Edge[this->E*sizeof(Edge)];
	}
};

int find(int* parent, int x){
	if(parent[x] == -1)
		return x;
	return find(parent, parent[x]);
}

void Union(int* parent, int x, int y){
	int xset = find(parent, x);
	int yset = find(parent, y);
	if(xset != yset){
		parent[xset] = yset;
	}
}

int isCycle(Graph* gh){
	int* parent = new int[gh->V*sizeof(int)];
	for(int i=0; i<gh->V; i++){
		parent[i] = -1;
	}
	for(int i=0; i<gh->E; i++){
		int x = find(parent, gh->edge[i].src);
		int y = find(parent, gh->edge[i].des);
		if(x == y) return 1;
		Union(parent, x, y);
	}
	return 0;
}


int main()
{
    /* Let us create the following graph
        0
        | \
        | \
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
        cout<<"graph contains cycle";
    else
        cout<<"graph doesn't contain cycle";

    return 0;
}
