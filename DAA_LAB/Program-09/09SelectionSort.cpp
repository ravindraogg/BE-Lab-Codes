/******************************************************************************
*File			: 09SelectionSort.cpp
*Description	: Program to sort an array using Selection Sort
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

class SelectionSort{
    vector <int> numList;
    int iNum;
    public:

    void fnGenRandArray(int);
    void fnSelectionSort();
    void fnDispArray();
    void fnSwap(int&, int&);
};

int main( int argc, char **argv)
{

    struct timespec tv;
    int iChoice, i, iNum;
    double dStart, dEnd;
    SelectionSort myListObj;
	ofstream fout("SelectionPlot.dat", ios::out);
    for(;;)
    {
        cout << "\n1.Selection Sort\n2.Plot the Graph\n3.Exit" ;
        cout << "\nEnter your choice\n";
        cin >> iChoice;
        switch(iChoice)
        {
            case 1:
                    cout << "\nEnter number of elements to sort : "; cin >> iNum;
                    myListObj.fnGenRandArray(iNum);
                    cout << "\nUnsorted Array" << endl;
                    myListObj.fnDispArray();
                    myListObj.fnSelectionSort();
                    cout << "\nSorted Array" << endl;
                    myListObj.fnDispArray();
                    break;

            case 2: for(i=100;i<20000;i+=100)
                    {
                        myListObj.fnGenRandArray(i);
                        clock_gettime(CLOCK_REALTIME, &tv);
                        dStart = tv.tv_sec + tv.tv_nsec/1000000000.0;
                        myListObj.fnSelectionSort();
                        clock_gettime(CLOCK_REALTIME, &tv);
                        dEnd = tv.tv_sec + tv.tv_nsec/1000000000.0;

                        fout << i << "\t" << setprecision(10) << dEnd - dStart << endl;
                    }
                    cout << "\nData File generated and stored in file < SelectionPlot.dat >.\n Use a plotting utility\n";
                    break;
            case 3:
                    exit(0);
        }
    }
    fout.close();
    return 0;
}

/******************************************************************************
*Function: fnSelectionSort
*Description: Function to sort elements in an iaArray using Quick Sort
*Function parameters:
*	int n - number of elements to be sorted
******************************************************************************/
void SelectionSort :: fnSelectionSort()
{
	int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < iNum-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < iNum; j++) {
            if (numList[j] < numList[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        fnSwap(numList[min_idx], numList[i]);
    }
}

void SelectionSort::fnGenRandArray(int n)
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

void SelectionSort::fnDispArray()
{
    int i;
	for(i=0;i<iNum;i++)
	{
        cout << setw(8) << numList[i] << endl;
    }
}

void SelectionSort::fnSwap(int &a,int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
