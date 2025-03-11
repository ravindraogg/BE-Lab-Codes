/******************************************************************************
*File		: 03BWarshall.c
*Description: Program to find transitive closure of a given directed
*					graph using Warshall's algorithm.
*Author		: Prabodh C P
*Compiler	: gcc compiler 11.4.0, Ubuntu 22.04
*Date		: 31 Mar 2024
******************************************************************************/
#include <stdio.h>
const int MAX = 100;
void WarshallTransitiveClosure(int graph[MAX][MAX], int numVert);
/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	: 0 on success
******************************************************************************/
int main(void)
{
	int i, j, numVert;
	int graph[MAX][MAX];
	printf("Warshall's Transitive Closure\n");
	printf("Enter the number of vertices : ");
	scanf("%d",&numVert);
	printf("Enter the adjacency matrix :-\n");
	for (i=0; i<numVert; i++)
		for (j=0; j<numVert; j++)
			scanf("%d",&graph[i][j]);
	WarshallTransitiveClosure(graph, numVert);
	printf("\nThe transitive closure for the given graph is :-\n");
	for (i=0; i<numVert; i++)
	{
		for (j=0; j<numVert; j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/******************************************************************************
*Function	: WarshallTransitiveClosure
*Description	: Function to transitive closure of a given directed
*					graph using Warshall's algorithm.
*Input parameters:
*	int graph[MAX][MAX] - adjacency matrix of the input graph
*	int numVert - no of vertices in the graph
*RETURNS	: no value
******************************************************************************/
void WarshallTransitiveClosure(int graph[MAX][MAX], int numVert)
{
	int i,j,k;
	for (k=0; k<numVert; k++)
	{
		for (i=0; i<numVert; i++)
		{
			for (j=0; j<numVert; j++)
			{
				if (graph[i][j] || (graph[i][k] && graph[k][j]))
					graph[i][j] = 1;
			}
		}
	}
}
