#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
	int V;
	list<int> *adj;
	void topoUtil(int v, bool visited[], stack<int> &Stack){
		visited[v] = true;
		list<int>::iterator i;
		for(i = adj[v].begin(); i!=adj[v].end(); i++)
			if(!visited[*i])
				topoUtil(*i, visited, Stack);
		Stack.push(v);
	}
public:
	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int v, int w){
		adj[v].push_back(w);
	}
	void toposort(){
		stack<int> Stack;
		bool* visited = new bool[V];
		for(int i=0; i<V; i++)
			visited[i] = false;
		for(int i=0; i<V; i++){
			if(visited[i] == false)
				topoUtil(i, visited, Stack);
		}
		while(Stack.empty() == false){
			cout << Stack.top() << " ";
			Stack.pop();
		}
	}
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(0, 3);
    cout << "Following is a Topological Sort of the given graph \n";
    g.toposort();

    return 0;
}

////////////////


void Graph::topologicalSort()
{
	int i, vertex;
	queue<int> q;
	for (i = 0; i < numV; i++)
	if (indegree[i] == 0)
		q.push(i);
	bool *visited = new bool[numV];
	for (i = 0; i < numV; i++)
		visited[i] = false;
	while (!q.empty())
	{
		vertex = q.front();
		q.pop();
		cout << vertex;
		visited[vertex] = true;
		for (i = 0; i < numV; i++)
		if (matrix[vertex][i] == 1)
		{
			if (!(--indegree[i]))
				q.push(i);
		}
	}
	delete[]visited;
}