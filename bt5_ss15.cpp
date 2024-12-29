#include <stdio.h>
#define V 5

int graph[V][V]; 
int visited[V]; 
int recStack[V]; 

int isCyclicUtil(int v) {
    visited[v] = 1; 
    recStack[v] = 1; 

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) { 
            if (!visited[i]) { 
                if (isCyclicUtil(i)) {
                    return 1; 
                }
            } else if (recStack[i]) {
                return 1; 
            }
        }
    }

    recStack[v] = 0; 
    return 0; 
}

int isCyclic(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0; 
        recStack[i] = 0; 
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) { 
            if (isCyclicUtil(i)) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    int n, edges, u, v;

    printf("Nhap vao so dinh: ");
    scanf("%d", &n);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0; 
        }
    }

    printf("Nhap vao so canh: ");
    scanf("%d", &edges);

    printf("Nhap cac canh (u v): \n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
    }

    if (isCyclic(n)) {
        printf("Do thi co chu trinh.\n");
    } else {
        printf("Do thi khong co chu trinh.\n");
    }

    return 0;
}
