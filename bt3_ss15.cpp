#include<stdio.h>
#define V 5
// Ham duyet theo chieu sau DFS

int visited[V];
int graph[V][V];
void DFS(int v, int n){
	printf("%d",v);
	visited[v] = 1;
	for(int i = 0; i < n; i++){
		if(visited[i] == 0 && graph[v][i] == 1){
			DFS(i, n);
		}
	}
} 

int isConnected(int n) {
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
	int n, u, v, start, edges;
	printf("Nhap vao so dinh : ");
	scanf("%d",&n);
	
	printf("Nhap vao so canh : ");
	scanf("%d",&edges);
	
	printf("Nhap cac canh (dinh v) : ");
	for(int i = 0; i < edges; i++){
		scanf("%d %d",&u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	printf("Nhap vao dinh bat dau duyet : ");
	scanf("%d",&start);
	DFS(start, n);
	printf("\n"); 
	if (isConnected(n)) {
        printf("Do thi lien thong.\n");
    } else {
        printf("Do thi khong lien thong.\n");
    }
	return 0;
}

