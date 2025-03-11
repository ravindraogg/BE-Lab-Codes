#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int MAX = 10;

inline int max(int x, int y)
{
    return (x>y)?x:y;
}
class Knapsack
{
    int totalProfit;
    int weight[MAX];
    int profit[MAX];
    int capacity;
    int numOfObj;
    int subset[MAX];
    int table[MAX][MAX];

    public:
    Knapsack();
    void fnReadKnapDetails();
    void fnCalcProfit();
    void fnFindSubSet();
};

void Knapsack::fnReadKnapDetails()
{
    int i;
    cout << "Enter the maxium number of objects : ";
    cin >> numOfObj;

    cout << "Enter the weights : \n";
    for (i=1; i<=numOfObj; i++)
    {
        cout << "Weight " << i << ": ";
        cin >> weight[i];
    }
    cout << "\nEnter the profits : \n";
    for (i=1; i<=numOfObj; i++)
    {
        cout << "Profit " << i << ": ";
        cin >> profit[i];
    }
    cout << "\nEnter the maximum capacity : ";
    cin >> capacity;
}

Knapsack :: Knapsack()
{
    int i;
    totalProfit = 0;
    for( i=1; i<=numOfObj; i++)
        subset[i] = 0;
}
void Knapsack::fnCalcProfit()
{
    int i,j;
    for (j=0; j<=capacity; j++)
        table[0][j] = 0;
    for (i=0; i<=numOfObj; i++)
        table[i][0] = 0;
    for (i=1; i<=numOfObj; i++)
    {
        for (j=1; j<=capacity; j++)
        {
            if (j-weight[i] < 0)
                table[i][j] = table[i-1][j];
            else
                table[i][j] = max(table[i-1][j], profit[i] + table[i-1][j-weight[i]]);
        }
    }
    totalProfit = table[numOfObj][capacity];
    cout << "\nProfit Matrix" << endl;
    for(i=0;i<=numOfObj; i++)
    {
    	for (j=0; j<=capacity; j++)
    	{
    		cout << setw(6) << table[i][j];
    	}
    	cout << endl;
    }
    cout << endl;
}

void Knapsack::fnFindSubSet()
{
    int i,j;
    i = numOfObj;
    j = capacity;
    while (i >= 1 && j >= 1)
    {
        if (table[i][j] != table[i-1][j])
        {
            subset[i] = 1;
            j = j - weight[i];
        }
        i--;
    }

    cout << "Items selected for the Knapsack are : " ;
    for(i=1;i<=numOfObj;i++)
    {
        if(subset[i] == 1)
        cout << i << " ";
    }
    cout << endl;
    cout << "Total Profit earned is " << totalProfit << endl;
}
int main()
{
    Knapsack knapsackObj;

    knapsackObj.fnReadKnapDetails();
    knapsackObj.fnCalcProfit();
    knapsackObj.fnFindSubSet();
    return 0;
}

