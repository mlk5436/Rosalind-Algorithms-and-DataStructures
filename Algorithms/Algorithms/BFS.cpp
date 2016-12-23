#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int numV = 0, numE = 0, v = 0, u = 0;
int dist[1000];
void BFS(int s);
FILE *dp = fopen("input.txt", "r");

int queue[1000];
int rear = -1, front = -1;
void enqueue(int Eitem);
void dequeue(int Ditem);
int main(){

	fscanf(dp, "%d", &numV);
	fscanf(dp, "%d", &numE);
	for (int i = 1; i <= numV; i++){
		dist[i] = INFINITY;
	}
	dist[1] = 0;
	enqueue(1);
	BFS(dist[1]);
	for (int i = 1; i < numV; i++){
		if (dist[i] == INFINITY){
			dist[i] == -1;
		}
		printf("%d ", dist[i]);
	}
	printf("\n");
	
	
}
void enqueue(int item){
	if (front == -1){
		front = 0;
	}
	rear = rear + 1;
	queue[rear] = item;
}

void dequeue(int item){
	if (front == -1 || front > rear)
		exit;
	front = front + 1;
}
void BFS(int s){
	int queueLength = sizeof(queue) / sizeof(queue[1]);
	while (queue[front]!= NULL){ // while queue is not empty
		u = queue[rear];
		dequeue(front);
		for (int i = 1; i <= numE; i++){
				fscanf(dp, "%d", &v);
				fscanf(dp, "%d", &u);
				if (dist[v] == INFINITY){
					enqueue(v);
					dist[v] = dist[u] + 1;
				}	
		}
	}
}