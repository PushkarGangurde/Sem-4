#include <iostream>
using namespace std;

#define MAX 20
#define INF 9999

class Prims
{
private:
    int cost[MAX][MAX];
    int nearest[MAX];
    int t[MAX][2];
    int n;

public:

    void accept()
    {
        cout << "Enter number of offices (nodes): ";
        cin >> n;

        cout << "\nEnter Cost Adjacency Matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> cost[i][j];

                // FIX: avoid changing diagonal elements
                if(i != j && cost[i][j] == 0)
                    cost[i][j] = INF;
            }
        }
    }

    void display()
    {
        cout << "\nCost Adjacency Matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(cost[i][j] == INF)
                    cout << "INF ";
                else
                    cout << cost[i][j] << " ";
            }
            cout << endl;
        }
    }

    void prims()
    {
        int start;
        int mincost = 0;
        int r = 0;

        cout << "\nEnter starting vertex: ";
        cin >> start;

        // validation
        if(start < 0 || start >= n)
        {
            cout << "Invalid starting vertex\n";
            return;
        }

        // initialize nearest array
        for(int i = 0; i < n; i++)
        {
            if(i != start)
                nearest[i] = start;
        }

        nearest[start] = -1;

        // run for n-1 edges
        for(int i = 1; i < n; i++)
        {
            int min = INF;
            int j = -1;   // FIX: initialized

            for(int k = 0; k < n; k++)
            {
                if(nearest[k] != -1 && cost[k][nearest[k]] < min)
                {
                    min = cost[k][nearest[k]];
                    j = k;
                }
            }

            if(j == -1)
            {
                cout << "Graph is not connected\n";
                return;
            }

            t[r][0] = nearest[j];
            t[r][1] = j;

            cout << "\nEdge Selected: " << nearest[j]
                 << " -> " << j
                 << " Cost: " << cost[j][nearest[j]];

            mincost += cost[j][nearest[j]];
            r++;

            nearest[j] = -1;

            for(int k = 0; k < n; k++)
            {
                if(nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j])
                    nearest[k] = j;
            }
        }

        cout << "\n\nMinimum Cost Spanning Tree Edges:\n";

        for(int i = 0; i < r; i++)
        {
            cout << t[i][0] << " -> " << t[i][1] << endl;
        }

        cout << "\nTotal Minimum Cost = " << mincost << endl;
    }
};

int main()
{
    Prims p;

    p.accept();
    p.display();
    p.prims();

    return 0;
}