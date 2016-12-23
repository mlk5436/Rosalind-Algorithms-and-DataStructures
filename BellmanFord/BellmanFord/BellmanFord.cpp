#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <list>
#define a 1000
using namespace std;
void Bellman(bool adj[][a], int vertices, int weight[][a]);

int main() {
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL)
		return -1;
	int vertices = 0, edges = 0, weight[1000][1000];
	bool adj[1000][1000];
	fscanf(fp, "%d %d", &vertices, &edges);
	for (int i = 1; i <= edges; i++) {
		int u = 0, v = 0, w = 0;
		fscanf(fp, "%d %d %d", &u, &v, &w);
		weight[u][v] = w;
		//printf("Weight[%d][%d]: %d ", u, v, weight[u][v]);
		adj[u][v] = true;
	}
	fclose(fp);
	Bellman(adj, vertices, weight);
	return 0;
}
void Bellman(bool adj[][a], int vertices, int weight[][a]) {
	int dist[1000];
	for (int i = 1; i <= vertices; i++) {
		dist[i] = INT_MAX;
	}
	dist[1] = 0;
	for (int k = 1; k <= vertices - 1; k++) {
		for (int i = 1; i <= vertices; i++) {
			for (int j = 1; j <= vertices; j++) {
				if (adj[i][j] == true) {
					if (dist[i]!= INT_MAX && dist[j] > dist[i] + weight[i][j]) {
						dist[j] = dist[i] + weight[i][j];
					}
				}
			}
		}
	}

	FILE *ofp = fopen("output.txt", "w");
	for (int i = 1; i <= vertices; i++) {
		if (dist[i] == INT_MAX)
			fprintf(ofp, "x ");
		else
			fprintf(ofp, "%d ", dist[i]);
	}
	fclose(ofp);
}