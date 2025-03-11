#include <stdio.h>
const int MAX = 10;
void fnTopological(int a[MAX][MAX], int n);


int main( int argc, char **argv)
{
	int graph[MAX][MAX],n;
	int i,j;
	printf("Topological Sorting Algorithm -\n");
	printf("\nEnter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix (graph should be a DAG)\n");
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			scanf("%d",&graph[i][j]);
	fnTopological(graph,n);
	printf("\n");
	return 0;
}

/******************************************************************************
*Function: fnTopological
*Description: Function to find Topological ordering of nodes in a DAG
*Input parameters:
*	int graph[MAX][MAX] - adjacency matrix of the input graph
*	int n - no of vertices in the graph
*RETURNS: no value
******************************************************************************/
void fnTopological(int graph[MAX][MAX], int n)
{
	int in[MAX], out[MAX], stack[MAX], top=-1;
	int i,j,k=0;
	for (i=0;i<n;i++)
	{
		in[i] = 0;
		for (j=0; j<n; j++)
			if (graph[j][i] == 1)
				in[i]++;
	}	
	
	while(1)
	{
		for (i=0;i<n;i++)
		{
			if (in[i] == 0)
			{
				stack[++top] = i;
				in[i] = -1;
			}
		}
		if (top == -1)
		break;
		out[k] = stack[top--];
		for(i=0;i<n;i++)
		{
			if (graph[out[k]][i] == 1)
				in[i]--;
		}
		k++;		
	}
	printf("Topological Sorting (JOB SEQUENCE) is:- \n");
	for (i=0;i<k;i++)
		printf("%d\t", out[i] + 1);
	printf("\n");
}

