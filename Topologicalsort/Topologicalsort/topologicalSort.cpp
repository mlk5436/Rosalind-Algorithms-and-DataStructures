#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <list>
#define a 1000

using namespace std;
class Graph
{
	int V;   
	list<int> *adj;
public:
	Graph(int V);  
	void addEdge(int v, int w);
	void explore(int v, stack <int> &topSort, bool visited[], int numV);
	void DFS(int numV, bool visited[], stack <int> &topSort);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::explore(int v, stack <int> &topSort, bool visited[], int numV) {
	visited[v] = true;
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++) {
		if (visited[*i] == false) {
			explore(*i, topSort, visited, numV);
		}
	}
	topSort.push(v);
}

void Graph::DFS(int numV, bool visited[], stack <int> &topSort) {
	int Count = 0;
	FILE *ofp = fopen("output.txt", "w");
	for (int i = 1; i <= numV; i++)
		visited[i] = false;
	for (int i = 1; i <= numV; i++) {
		if (visited[i] == false) {
			explore(i, topSort, visited, numV);
		}
	}
	while (topSort.empty() == false) {
		fprintf(ofp, "%d ", topSort.top());
		topSort.pop();
	}
	fclose(ofp);
}


int main() {
	bool visited[1000];
	int k = 0;
	int numV = 0, numE = 0;
	stack <int> topSort;
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL)
		return -1;
	fscanf(fp, "%d %d", &numV, &numE);
	int v = 0, u = 0;
	Graph g(numV+1);
	for (int i = 1; i <= numE; i++) {
		fscanf(fp, "%d %d", &v, &u);
		g.addEdge(v, u);
	}
	fclose(fp);
	g.DFS(numV, visited, topSort);

	return 0;
}
