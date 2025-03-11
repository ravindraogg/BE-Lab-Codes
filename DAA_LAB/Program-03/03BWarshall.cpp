/******************************************************************************
*File		: 03BWarshall.cpp
*Description: Program to find transitive closure of a given directed
*					graph using Warshall's algorithm.
*Author		: Prabodh C P
*Compiler	: g++ compiler 11.4.0, Ubuntu 22.04
*Date		: 31 Mar 2024
******************************************************************************/
#include <iostream>
using namespace std;

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
	cout << "Warshall's Transitive Closure" << endl;
	cout << "Enter the number of vertices : " ;
	scanf("%d",&numVert);
	cout << "Enter the adjacency matrix :-" << endl;
	for (i=0; i<numVert; i++)
		for (j=0; j<numVert; j++)
			scanf("%d",&graph[i][j]);
	WarshallTransitiveClosure(graph, numVert);
	cout << "\nThe transitive closure for the given graph is :-" << endl;
	for (i=0; i<numVert; i++)
	{
		for (j=0; j<numVert; j++)
		{
			cout << graph[i][j] << "\t";
		}
		cout << "" << endl;
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
