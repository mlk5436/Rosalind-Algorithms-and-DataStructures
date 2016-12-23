#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <list>
#define a 10000

using namespace std;
class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	int findPath(int vertices, int src, int dest);
	int semiConnected(int vertices, Graph g);
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

int Graph::findPath(int vertices, int src, int dest) {
	bool visited[10000];
	for (int i = 1; i <= vertices; i++)
		visited[i] = false;
	visited[src] = true;
	list <int> List;
	list<int>::iterator i;
	List.push_back(src);
	while (!List.empty()) {
		int u = List.front();
		List.pop_front();
		for (i = adj[u].begin(); i != adj[u].end(); i++) {
			if (*i == dest)
				return 1;
			if (visited[*i] == false) {
				visited[*i] = true;
				List.push_back(*i);
			}
		}
	}
	return -1;
}
int Graph::semiConnected(int vertices, Graph g) {
	int check = 0, checks = 0, count = 0;
	for (int j = 1; j <= vertices; j++) {
		for (int k = j + 1; k <= vertices; k++) {
			check = g.findPath(vertices, j, k);
			if (check != 1)
				checks = g.findPath(vertices, k, j);
			//printf("(%d, %d) check: %d, checks: %d\n", j, k, check, checks);
			if (check == -1 && checks == -1)
				return -1;
			check = 0, checks = 0;
		}
	}
	return 1;
}
int main() {

	FILE *fp = fopen("input.txt", "r");
	FILE *ofp = fopen("output.txt", "w");
	if (fp == NULL || ofp == NULL)
		return -1;
	int num = 0, vertices = 0, edges = 0;
	fscanf(fp, "%d", &num);
	for (int i = 1; i <= num; i++) {
		fscanf(fp, "%d %d", &vertices, &edges);
		Graph g(vertices+1);
		for (int j = 1; j <= edges; j++) {
			int u = 0, v = 0;
			fscanf(fp, "%d %d", &u, &v);
			g.addEdge(u, v);
		}
		
		if (g.semiConnected(vertices, g) == 1)
			fprintf(ofp, "%d ", 1);
		else
			fprintf(ofp, "%d ", -1);
		printf("\n\n");
	}
	fclose(fp);
	fclose(ofp);

	return 0;
}