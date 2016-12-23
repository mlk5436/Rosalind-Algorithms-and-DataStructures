#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

bool visited[1000];
int adj[1000][1000];
int k = 0;
int numV = 0, numE = 0, ccnum = 0;
void DFS();
void explore(int v);
int main(){

	FILE *fp = fopen("rosalind_cc.txt", "r");
	fscanf(fp, "%d", &numV);
	fscanf(fp, "%d", &numE);
	int v=0, u=0;
	// create adjacent list
	for (int i = 0; i < numE; i++){
		fscanf(fp, "%d ", &v);
		fscanf(fp, "%d ", &u);
		adj[v][v] = 1;
		adj[v][u] = 1;
		adj[u][v] = 1;
	}
	fclose(fp);
	/*
	printf("n: %d, m: %d\n", numV, numE);
	for (int i = 1; i <= numV; i++){
		for (int j = 1; j <= numV; j++)
			printf("%d ", adj[i][j]);
		printf("\n");
	}
	*/
	DFS();
	printf("number of connected component: %d \n", ccnum);
	
	return 0;
}

void DFS(){
	for (int i = 1; i <= numV; i++)
		visited[i] = false;
	for (int i = 1; i <= numV; i++){
		if (visited[i] == false){
			ccnum++;
			explore(i);
		}
	}
	/*
	for (int i = 1; i <= numV; i++)
		printf("visited[%d]: %d \n", i, visited[i]);
		*/
}

void explore(int v){
	visited[v] = true;
	for (int j = 1; j <= numV; j++){
		//printf("explore root %d vertex %d\n", v, j);
		if (visited[j] == false && adj[v][j] == 1){
			explore(j);
			
		}
	}
	
}