#include <stdio.h>
#include <stdlib.h>

int DFS();
bool visited[1000];
int G[1000][2];
int explore(int V);
int numV = 0, numE = 0, ccnum = 0;

int main(){
	
	FILE *fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &numV);
	fscanf(fp, "%d", &numE);
	
	for (int i = 0; i < numE; i++){
		for (int j = 0; j < 2; j++)
			fscanf(fp, "%d", &G[i][j]);
	}
	fclose(fp);
	printf("n: %d, m: %d\n", numV, numE);
	for (int i = 0; i < numE; i++){
		for (int j = 0; j < 2; j++){
			//printf("%d ", G[i][j]);
		}
		printf("\n");
		
	}
	
	ccnum = DFS();
	for (int i = 1; i <= numV; i++){
		if (visited[i] == false){
			//printf("vertex %d is still false\n", i);
			ccnum++;
		}
	}
	printf("number of connected component: %d \n", ccnum);
	return 0;
}

int DFS(){
	int num = 0;
	for (int i = 1; i <= numV; i++){
		visited[i] = false;
	}
	for (int i = 1; i <= numV; i++){
		if (visited[i] == false){
			i = explore(i);
			//printf("Vertex returned from explore is %d\n", i);
			i = i - 1;
		}
		num++;
		//printf("ccnum is %d\n", num);
	}

	return num;
}

int explore(int v){
	int i = 0, j = 0;
	visited[v] = true;
	//printf("visited(%d) is %d\n", v, visited[v]);
	for (i; i < numE; i++){
		//printf("v is %d,iteration %d, looking at vertex: %d\n", v, i, G[i][0]);
		if (G[i][0] == v){
		//printf("G[%d][1] is %d, visited(%d) is %d\n",i, G[i][1], G[i][1], visited[G[i][1] - 1]);
			if (visited[G[i][1]] == false){
				visited[G[i][1]] = true;
				//printf("1visited(%d) = %d\n", G[i][1], visited[G[i][1]]);
			}
		}
		else if (visited[G[i][0]]== true){
			if (visited[G[i][1]] == false){
				visited[G[i][1]] = true;
				//printf("visited(%d) = %d\n", G[i][1], visited[G[i][1]]);
			}
			//else
				//printf("visited(%d) = %d\n", G[i][1], visited[G[i][1]]);
		}
		else if ((G[i][0] != v + 1 && visited[G[i][0]] == false)|| i == numE-1){
			for (int j = 1;j <= numV; j++)
			//printf("vertex: %d %d\n", j, visited[j]);
			return G[i][0];
		}
	}
	
}