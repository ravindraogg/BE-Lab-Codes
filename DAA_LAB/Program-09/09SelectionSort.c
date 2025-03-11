/********************************************************************************
*File		: 09SelectionSort.c
*Description	: Program to sort an array using Selection Sort
*Author			: Prabodh C P
*Compiler	: gcc compiler 11.4.0, Ubuntu 22.04
*Date		: 31 Mar 2024
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


void fnGenRandInput(int [], int);
void fnDispArray( int [], int);
void fnSelectionSort(int [], int);

/******************************************************************************
*Function	: main
*Function parameters:
*	int argc - no of commamd line arguments
*	char **argv - vector to store command line argumennts
*RETURNS	:	0 on success
******************************************************************************/

int main( int argc, char **argv)
{

	FILE *fp;
	struct timeval tv;
	double dStart,dEnd;
	int iaArr[500000],iNum,i,iChoice;

    for(;;)
    {
        printf("\n1.Plot the Graph\n2.Selection Sort\n3.Exit");
        printf("\nEnter your choice\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                fp = fopen("SelectionPlot.dat","w");

                for(i=100;i<20000;i+=100)
                {
                    fnGenRandInput(iaArr,i);

                    gettimeofday(&tv,NULL);
                    dStart = tv.tv_sec + (tv.tv_usec/1000000.0);

                    fnSelectionSort(iaArr,i);

                    gettimeofday(&tv,NULL);
                    dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);

                    fprintf(fp,"%d\t%lf\n",i,dEnd-dStart);

                }
                fclose(fp);

                printf("\nData File generated and stored in file < SelectionPlot.dat >.\n Use a plotting utility\n");
            break;

            case 2:
                printf("\nEnter the number of elements to sort\n");
                scanf("%d",&iNum);
                printf("\nUnsorted Array\n");
                fnGenRandInput(iaArr,iNum);
                fnDispArray(iaArr,iNum);
                fnSelectionSort(iaArr,iNum);
                printf("\nSorted Array\n");
                fnDispArray(iaArr,iNum);
            break;

            case 3:
                exit(0);
        }
    }

	return 0;
}


/******************************************************************************
*Function	: GenRandInput
*Description	: Function to generate a fixed number of random elements
*Function parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	:no return value
******************************************************************************/

void fnGenRandInput(int X[], int n)
{
	int i;

	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		X[i] = rand()%10000;
	}

}

/******************************************************************************
*Function	: DispArray
*Description	: Function to display elements of an array
*Function parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	: no return value
******************************************************************************/

void fnDispArray( int X[], int n)
{
	int i;

	for(i=0;i<n;i++)
		printf(" %5d \n",X[i]);

}


/******************************************************************************
*Function	: fnSelectionSort
*Description	: Function to sort elements in an array using Selection Sort
*Input parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	: no return value
******************************************************************************/

void fnSelectionSort(int X[], int n)
{
	int i,j,iTemp,iMin;
	for(i=0;i<n;i++)
	{
		iMin = i;
		for(j = i+1;j<n;j++)
		{
			if(X[j] < X[iMin])
				iMin = j;
		}

		iTemp = X[i];
		X[i] = X[iMin];
		X[iMin] = iTemp;
	}
}

