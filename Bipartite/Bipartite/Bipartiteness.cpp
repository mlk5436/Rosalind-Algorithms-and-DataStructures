#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#define a 1000
using namespace std;

int bipartite(bool adj[][a], int vertices);

int main() {

	FILE *ofp = fopen("output.txt", "w");
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL)
		return -1;
	if (ofp == NULL)
		return -1;
	int num = 0, vertices = 0, edges = 0, check = 0;
	bool adj[1000][1000];
	
	fscanf(fp, "%d", &num);
	for (int i = 1; i <= num; i++) {
		fscanf(fp, "%d %d", &vertices, &edges);
		for (int j = 1; j <= vertices; j++) {
			for (int k = 1; k <= vertices; k++) {
				adj[j][k] = false;
			}
		}
		for (int j = 1; j <= edges; j++) {
			int v = 0, u = 0;
			fscanf(fp, "%d %d", &v, &u);
			adj[v][u] = true;
			adj[u][v] = true;
		}

		check = bipartite(adj, vertices);
		fprintf(ofp, "%d ", check);
	}
	fclose(ofp);
	fclose(fp);
	return 0;
}


int bipartite(bool adj[][a], int vertices) {
	int color[1000];
	for (int j = 1; j <= vertices; j++) {
		color[j] = -1;
	}

	color[1] = 1;
	queue <int> que;
	que.push(1);

	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int v = 1; v <= vertices; v++) {
			if (adj[u][v] == true&& color[v] == -1) {
				color[v] = 1 - color[u];
				que.push(v);
			}
			else if (adj[u][v] == true && color[v] == color[u])
				return -1;
		}

	}

	return 1;

}

