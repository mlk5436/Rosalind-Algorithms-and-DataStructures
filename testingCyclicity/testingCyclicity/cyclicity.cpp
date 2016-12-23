#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define a 1000

int DFS(bool adj[][a], bool visited[], int vertices);
void explore(bool adj[][a], bool visited[], int v, int vertices);
void previsit(int v);
void postvisit(int v);
int clock = 1, check = 1;
int prev[1000], post[1000];

int main() {
	FILE *fp = fopen("input.txt", "r");
	FILE *ofp = fopen("output.txt", "w");
	if (fp == NULL || ofp == NULL)
		return -1;
	int num = 0, check = 0;
	bool visited[1000], adj[1000][1000];
	
	fscanf(fp, "%d", &num);
	for (int i = 1; i <= num; i++) {
		int vertices = 0, edges = 0;
		fscanf(fp, "%d %d", &vertices, &edges);
		for (int j = 1; j <= vertices; j++) {
			for (int k = 1; k <= vertices; k++)
				adj[j][k] = false;
		}
		for (int j = 1; j <= edges; j++) {
			int u = 0,v = 0;
			fscanf(fp, "%d %d", &v, &u);
			adj[v][u] = true;
		}
		/*
		for (int j = 1; j <= vertices; j++) {
			for (int k = 1; k <= vertices; k++)
				if(adj[j][k]== true)
					printf("%d %d \n", j, k);
		}
		*/
		
	
		fprintf(ofp, "%d ", DFS(adj, visited, vertices));
	}
	fclose(fp);
	fclose(ofp);

	return 0;
}

int DFS(bool adj[][a], bool visited[], int numV) {
	clock = 1;
	check = 1;
	for (int i = 1; i <= numV; i++) {
		visited[i] = false;
		prev[i] = 0;
		post[i] = 0;
	}

	for (int i = 1; i <= numV; i++) {
		if (visited[i] == false) {
			explore(adj, visited, i, numV);
		}
	}
	for (int i = 1; i <= numV; i++) {
		//printf("pre[%d]: %d, post[%d]: %d \n", i, prev[i], i, post[i]);
	}
	for (int u = 1; u <= numV; u++) {
		for (int v = 1; v <= numV; v++) 
		{
			if (adj[u][v] == true) {
				//printf("u: %d v: %d , prev[v]: %d, prev[u]: %d, post[u]: %d, post[v]: %d\n", u, v, prev[v], prev[u], post[u], post[v]);
				if ((prev[v] < prev[u]) && (prev[u]< post[u]) && (post[u] < post[v])) {
					check = -1;
					//printf("cycle \n");
				}
			}
			
		}
	}
		
	return check;
}

void explore(bool adj[][a], bool visited[], int v, int numV) {
	visited[v] = true;
	previsit(v);
	for (int j = 1; j <= numV; j++) {
		//printf("explore root %d vertex %d\n", v, j);
		if (adj[v][j] == true) {
			if (visited[j] == false) {
				explore(adj, visited, j, numV);
				//printf("explore at vertex %d", j);
			}
		}
	}
	postvisit(v);

}
void previsit(int v) {
	prev[v] = clock;
	clock++;
	//printf("prev[%d]: %d \n", v, prev[v]);
}

void postvisit(int v) {
	post[v] = clock;
	clock++;
	//printf("post[%d]: %d \n", v, post[v]);
}
