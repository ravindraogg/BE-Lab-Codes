/***************************************************************************
*File		: 03AFloyd.cpp
*Description: Program to implement Floyd's Algorithm
*Author		: Prabodh C P
*Compiler	: g++ compiler 11.4.0, Ubuntu 22.04
*Date		: 31 Mar 2024
***************************************************************************/
#include <iostream>
using namespace std;
/******************************************************************************
*Function	: 	main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int iN, i, j, k;
	int iaFloyd[10][10], iaCost[10][10];
	cout << "\n*********************************************************";
	cout << "\n*\tPROGRAM TO IMPLEMENT FLOYD'S ALGORITHM\t*\n";
	cout << "*********************************************************";
	cout << "\nEnter the number of vertices\n";
	cin >> iN;
	cout << "\nEnter the Cost adjacency Matrix\n";
	for(i=0;i<iN;i++)
		for(j=0;j<iN;j++)
			cin >> iaCost[i][j];
	cout << "\nInput Graph\n";
	for(i=0;i<iN;i++)
	{
		for(j=0;j<iN;j++)
		{
			cout << iaCost[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

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
	cout << "\nAll Pair Shortest Path Matrix\n";
	for(i=0;i<iN;i++)
	{
		for(j=0;j<iN;j++)
		{
			cout << iaFloyd[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n";
	return 0;
}
