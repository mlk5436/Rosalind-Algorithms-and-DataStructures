#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int V = 0, E = 0, v = 0, u = 0;
	int vertices[1001];
	FILE *fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &V);
	fscanf(fp, "%d", &E);
	//printf("# of vertices: %d, # of edges: %d\n", V, E);
	for (int i = 0; i <= V; i++) {
		vertices[i] = 0;
	}
	for (int i = 1; i <= E; i++) {
		fscanf(fp, "%d %d", &v, &u);
		//printf("(%d) v: %d, u: %ad \n", i, v, u);
		vertices[v]++;
		vertices[u]++;
	}
	fclose(fp);

	FILE *fp1 = fopen("output.txt", "w");
	for (int i = 1; i <= V; i++) {
		fprintf(fp1, "%d ", vertices[i]);
	}
	fclose(fp1);

	return 0;
}

