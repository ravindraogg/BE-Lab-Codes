/******************************************************************************
*File		: 04Dijkstra.c
*Description: Program to find shortest paths to other vertices using 
*				Dijkstra's algorithm.
*Author		: Prabodh C P
*Compiler	: gcc compiler 11.4.0, Ubuntu 22.04
*Date		: 31 Mar 2024
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

const int MAXNODES = 10,INF = 9999;
void fnDijkstra(int [MAXNODES][MAXNODES], int [MAXNODES], int [MAXNODES], int[MAXNODES], int, int, int);
/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	: 0 on success
******************************************************************************/
int main(void)
{
	int n,cost[MAXNODES][MAXNODES],dist[MAXNODES],visited[MAXNODES],path[MAXNODES],i,j,source,dest;
	printf("\nEnter the number of nodes\n");
	scanf("%d", &n);
	printf("Enter the Cost Matrix\n\n");
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d", &cost[i][j]);
	printf("Enter the Source vertex\n");
	scanf("%d", &source);
	
	printf("\n//For Source Vertex : %d shortest path to other vertices//\n", source);
	for (dest=0; dest < n; dest++)
	{
		fnDijkstra(cost,dist,path,visited,source,dest,n);
		if (dist[dest] == INF)
		printf("%d not reachable\n\n", dest);
		else
		{
			printf("\n");
			i = dest;
			do
			{
				printf("%d <--", i);
				i = path[i];
			}while (i!= source);
			printf("%d = %d\n", i, dist[dest]);
		}
	}
	
	return 0;
}

/******************************************************************************
*Function	: fnDijkstra
*Description	: Function to find shortest paths to other vertices
* using Dijkstra's algorithm.
*Input parameters:
*	int c[][] - cost adjacency matrix of the graph
*	int d[] - distance vector
*	int p[] - path vector
*	int s[] - vector to store visited information
*	int so	- source vertex
*	int de	- destination vertex
*	int n - no of vertices in the graph
*RETURNS	: no value
******************************************************************************/
void fnDijkstra(int c[MAXNODES][MAXNODES], int d[MAXNODES], int p[MAXNODES], 	int s[MAXNODES], int so, int de, int n)
{
	int i,j,a,b,min;
	for (i=0;i<n;i++)
	{
		s[i] = 0;
		d[i] = c[so][i];
		p[i] = so;
	}
	s[so] = 1;
	for (i=1;i<n;i++)
	{
		min = INF;
		a = -1;
		for (j=0;j<n;j++)
		{
			if (s[j] == 0)
			{
				if (d[j] < min)
				{
					min = d[j];
					a = j;
				}
			}
		}
		if (a == -1) return;
		s[a] = 1;
		if (a == de) return;

		for (b=0;b<n;b++)
		{
			if (s[b] == 0)
			{
				if (d[a] + c[a][b] < d[b])
				{
					d[b] = d[a] + c[a][b];
					p[b] = a;
				}
			}
		}
	}
}
