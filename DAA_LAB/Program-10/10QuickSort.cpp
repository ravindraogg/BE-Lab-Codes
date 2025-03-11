/******************************************************************************
*File			: 10QuickSort.cpp
*Description	: Program to sort an array using Quick Sort
*Author			: Prabodh C P
*Compiler	: g++ compiler 11.4.0, Ubuntu 22.04
*Date		: 31 Mar 2024
******************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class QuickSort{
    vector <int> numList;
    int iNum;
    public:

    void fnGenRandArray(int);
    void fnQuickSort(int, int);
    void fnDispArray();
    int fnPartition(int ,int);
    void fnSwap(int&, int&);
};

int main( int argc, char **argv)
{

    struct timespec tv;
    int iChoice, i, iNum;
    double dStart, dEnd;
    QuickSort myListObj;
	ofstream fout("QuickPlot.dat", ios::out);
    for(;;)
    {
        cout << "\n1.Quick Sort\n2.Plot the Graph\n3.Exit" ;
        cout << "\nEnter your choice\n";
        cin >> iChoice;
        switch(iChoice)
        {
            case 1:
                    cout << "\nEnter number of elements to sort : "; cin >> iNum;
                    myListObj.fnGenRandArray(iNum);
                    cout << "\nUnsorted Array" << endl;
                    myListObj.fnDispArray();
                    myListObj.fnQuickSort(0,iNum-1);
                    cout << "\nSorted Array" << endl;
                    myListObj.fnDispArray();
                    break;

            case 2: for(i=100;i<100000;i+=100)
                    {
                        myListObj.fnGenRandArray(i);
                        clock_gettime(CLOCK_REALTIME, &tv);
                        dStart = tv.tv_sec + tv.tv_nsec/1000000000.0;
                        myListObj.fnQuickSort(0,i-1);
                        clock_gettime(CLOCK_REALTIME, &tv);
                        dEnd = tv.tv_sec + tv.tv_nsec/1000000000.0;

                        fout << i << "\t" << setprecision(10) << dEnd - dStart << endl;
                    }
                    cout << "\nData File generated and stored in file < QuickPlot.dat >.\n Use a plotting utility\n";
                    break;
            case 3:
                    exit(0);
        }
    }
    fout.close();
    return 0;
}


/******************************************************************************
*Function: fnPartition
*Description: Function to partition an iaArray using First element as Pivot
*Function parameters:
*	int l - start index of the subiaArray to be sorted
*	int r - end index of the subiaArray to be sorted
*RETURNS: integer value specifying the location of partition
******************************************************************************/
int QuickSort :: fnPartition(int l, int r)
{
	int i,j;
	int p;
	p = numList[l];
	i = l;
	j = r+1;
	do
	{
		do { i++; } while (numList[i] < p);
		do { j--; } while (numList[j] > p);
		fnSwap(numList[i], numList[j]);
	}while (i<j);
	fnSwap(numList[i], numList[j]);
	fnSwap(numList[l], numList[j]);
	return j;
}

/******************************************************************************
*Function: fnQuickSort
*Description: Function to sort elements in an iaArray using Quick Sort
*Function parameters:
*	int l - start index of the subiaArray to be sorted
*	int r - end index of the subiaArray to be sorted*RETURNS	: no value
******************************************************************************/
void QuickSort :: fnQuickSort(int l, int r)
{
	int s;
	if (l < r)
	{
		s = fnPartition(l, r);
		fnQuickSort(l, s-1);
		fnQuickSort(s+1, r);
	}
}

void QuickSort::fnGenRandArray(int n)
{
    int i, iVal;
	numList.clear();
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
        iVal = rand()%10000;
        numList.push_back(iVal);
	}
	iNum = n;
}

void QuickSort::fnDispArray()
{
    int i;
	for(i=0;i<iNum;i++)
	{
        cout << setw(8) << numList[i] << endl;
    }
}

void QuickSort::fnSwap(int &a,int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
