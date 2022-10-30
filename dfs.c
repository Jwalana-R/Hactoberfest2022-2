#include <stdio.h>  //Time Complexity : O(v^2); v=no of nodes      Space Complexity : O(v)
#include <stdlib.h>
#define N 100

int visitednodes[N];
int Adjmatrix[N][N];

void DFS(int x, int n)
{
    printf("%d ", x);
    visitednodes[x] = 1;
    for (int j = 0; j < n; j++)
    {
        if (Adjmatrix[x][j] == 1 && !visitednodes[j])
        {
            DFS(j, n);
        }
    }
}

void create_edge(int u, int v)
{ 
    Adjmatrix[u][v] = 1;
    Adjmatrix[v][u] = 1;
}

int main()
{
    int n,e,x;
    printf("enter no of nodes in graph:");
    scanf("%d", &n);
    printf("enter no of edges in graph:");
    scanf("%d", &e);
    printf("enter connected vertices:\n");
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        create_edge(u,v);
    }
    printf("the adjacency matrix is:\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
           printf("%d ",Adjmatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        visitednodes[i] = 0;
    }
    printf("enter node u wanna start with:");
    scanf("%d", &x);
    printf("DFS for given graph is:");
    DFS(x, n);

    return 0;
}
//Time Complexity : O(v^2); v=no of nodes
//Space Complexity : O(v)
