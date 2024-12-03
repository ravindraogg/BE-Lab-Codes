//BFS and DFS 
#include<stdio.h>
#include<stdlib.h>
int a[10][10],visited[10],n;
void BFS(int u)
{
    int f,r,q[10],v;
    printf("The nodes visited from %d:",u);
    f=0,r=-1;
    q[++r]=u;   // inserting into the queue
    visited[u]=1;
    printf("%d",u);
    while(f<=r)
    {
        u=q[f++]; // dequeuing
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1)
            {
                if(visited[v]==0)
                {
                    printf("%d",v);
                    visited[v]=1;
                    q[++r]=v;  // enqueuing
                }
            }

        }
    }
}
void DFS(int v)
{
    int w;
    visited[v]=1;
    printf("%d",v);
    for(w=0;w<n;w++)
    {
        if(a[v][w]==1 && visited[w]==0)
            DFS(w);
    }


}
int main()
{
    int i,j,choice,source,s1;
    printf("Graph traversals using Adjacency matrix\n");
    printf("Enter the no.of nodes:");
    scanf("%d",&n);
    printf("enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
    }
    for( ; ;)
    {
        printf("\nGraph Traversals using adjacency matrix\n");
        printf("1.Reachable nodes using BFS\n");
        printf("2.Reachable nodes using DFs\n");
        printf("3.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the source node:");
                scanf("%d",&s1);
                BFS(s1);
                for(i=0;i<n;i++)   // to mark unvisited so that DFS can also traverse
                    visited[i]=0;
                break;
            case 2:
                for(source=0;source<n;source++)
                {
                    for(i=0;i<n;i++)
                        visited[i]=0;
                    printf("\nReachable nodes from %d:",source);
                    DFS(source);
                }
                for(i=0;i<n;i++)
                    visited[i]=0;
                break;
            case 3:exit(0);

        }
    }
    return 0;
}