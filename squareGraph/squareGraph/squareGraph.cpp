#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#define a 1000

int count(int adj[][a], int j, int k, int n) {
	if (adj[j][k] == true && adj[n][k] == true) {
		return 1;
	}
	return 0;
}
int main() {

	FILE *fp = fopen("input.txt", "r");
	FILE *ofp = fopen("input.txt", "w");
	int num = 0, common[1000][1000];
	bool adj[1000][1000];
	fscanf(fp, "%d", &num);
	for (int i = 1; i <= num; i++) {
		int vertices = 0, edges = 0;
		fscanf(fp, "%d %d", &vertices, &edges);
		for (int j = 1; j <= vertices; j++) {
			for (int k = 1; k <= vertices; k++) {
					adj[j][k] = false;
			}
		}
		for (int j = 1; j <= edges; j++) {
			int u = 0, v = 0;
			fscanf(fp, "%d %d", &v, &u);
			adj[v][u] = true;
			adj[u][v] = true;
		}
		int c = 0;
		for (int j = 1; j <= vertices; j++) {
			for (int k = 1; k <= vertices; k++) {
				if (adj[j][k] == true) {
					c++;
					common[j][c] = k;
 				}
			}
			c = 0;
		}
	}
return 0;
}