
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAX = 10;

class Graph{
	int iNum;
	int iaGraph[MAX][MAX];
	vector <int> jobVector;
	public:
	friend istream& operator>>(istream&, Graph&);
	void fnCompTopoOrder();
	void fnDispTopoOrder();
};
istream& operator>>(istream &in, Graph &g)
{
	cout << "Enter the number of vertices : ";
	in >> g.iNum;

    cout << "\nEnter the adjacency matrix (graph should be a DAG)" << endl;
	for(int i=0;i<g.iNum;i++)
		for(int j=0;j<g.iNum;j++)
			in >> g.iaGraph[i][j];
	return in;
}

void Graph::fnCompTopoOrder()
{
    int i, j, k=0;
	vector <int> inDegree(MAX);
	stack <int> myStack;
	for(i=0;i<iNum;i++)
	{
		inDegree[i] = 0;
		for(j=0;j<iNum;j++)
		{
			inDegree[i] += iaGraph[j][i];
		}
	}

	while(1)
	{
		for(i=0;i<iNum;i++)
		{
			if(inDegree[i] == 0)
			{
				myStack.push(i);
				inDegree[i] = -1;
			}

		}
		if(myStack.empty())
            break;

        jobVector.push_back(myStack.top());
        myStack.pop();
		for(i=0;i<iNum;i++)
		{
            if(iaGraph[jobVector[k]][i])
            {
                inDegree[i]--;
            }
		}
		k++;
	}
}

void Graph::fnDispTopoOrder()
{
    cout << "Topological Ordering (JOB SEQUENCE) is:";
    for(size_t i=0; i<jobVector.size(); i++)
    {
        cout << jobVector[i]+1 << "\t";
    }
    cout << endl;
}

int main()
{
    Graph myGraph;

    cin >> myGraph;

    myGraph.fnCompTopoOrder();
    myGraph.fnDispTopoOrder();
    return 0;
}

