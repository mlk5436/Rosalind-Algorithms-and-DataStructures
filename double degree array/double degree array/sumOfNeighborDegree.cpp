#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int V = 0, E = 0, v = 0, u = 0;
	int vertices[1001];
	bool adjlist[1001][1001];
	int doubleArr[1001];

	FILE *fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &V);
	fscanf(fp, "%d", &E);
	//printf("# of vertices: %d, # of edges: %d\n", V, E);
	for (int i = 1; i <= V; i++) {
		vertices[i] = 0;
		doubleArr[i] = 0;
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			adjlist[i][j] = false;
		}
	}
	for (int i = 1; i <= E; i++) {
		fscanf(fp, "%d %d", &v, &u);
		//printf("(%d) v: %d, u: %ad \n", i, v, u);
		adjlist[v][u] = true;
		adjlist[u][v] = true;
		vertices[v]++;
		vertices[u]++;
	}
	fclose(fp);
	/*
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			printf("%d ", adjlist[i][j]);
		}
		printf("\n");
	}
	*/
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (adjlist[i][j] == true) {
				doubleArr[i] = doubleArr[i] + vertices[j];
			}
		}
	}
	FILE *fp1 = fopen("output.txt", "w");
	for (int i = 1; i <= V; i++) {
		fprintf(fp1, "%d ", doubleArr[i]);
	}
	fclose(fp1);

	return 0;
}

