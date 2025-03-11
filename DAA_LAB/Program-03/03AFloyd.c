/***************************************************************************
*File		: 03AFloyd.c
*Description: Program to implement Floyd's Algorithm
*Author		: Prabodh C P
*Compiler	: gcc compiler 11.4.0, Ubuntu 22.04
*Date		: 31 Mar 2024
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/******************************************************************************
*Function	: 	main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int iN, i, j, k;
	int iaFloyd[10][10], iaCost[10][10];
	printf("\n*********************************************************");
	printf("\n*\tPROGRAM TO IMPLEMENT FLOYD'S ALGORITHM\t*\n");
	printf("*********************************************************");
	printf("\nEnter the number of vertices\n");
	scanf("%d",&iN);
	printf("\nEnter the Cost adjacency Matrix\n");
	for(i=0;i<iN;i++)
		for(j=0;j<iN;j++)
			scanf("%d",&iaCost[i][j]);
	printf("\nInput Graph\n");
	for(i=0;i<iN;i++)
	{
		for(j=0;j<iN;j++)
		{
			printf("%d\t",iaCost[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(i=0;i<iN;i++)
	{
		for(j=0;j<iN;j++)
		{
			iaFloyd[i][j] = iaCost[i][j];
		}
	}

	for(k=0;k<iN;k++)
	{
		for(i=0;i<iN;i++)
		{
			for(j=0;j<iN;j++)
			{
				if(iaFloyd[i][j] > (iaFloyd[i][k] + iaFloyd[k][j]))
					iaFloyd[i][j] = (iaFloyd[i][k] + iaFloyd[k][j]);
			}
		}
	}
	printf("\nAll Pair Shortest Path Matrix\n");
	for(i=0;i<iN;i++)
	{
		for(j=0;j<iN;j++)
		{
			printf("%d\t",iaFloyd[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
