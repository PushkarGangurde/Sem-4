#include <iostream>
using namespace std;

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int w[n+1], v[n+1];

    cout << "Enter weights:\n";
    for(int i = 1; i <= n; i++)
        cin >> w[i];

    cout << "Enter values (profits):\n";
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    cout << "Enter capacity W: ";
    cin >> W;

    int B[n+1][W+1];

    // first row
    for(int j = 0; j <= W; j++)
        B[0][j] = 0;

    // first column
    for(int i = 1; i <= n; i++)
        B[i][0] = 0;

    // fill table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if(w[i] <= j)
            {
                if(v[i] + B[i-1][j - w[i]] > B[i-1][j])
                    B[i][j] = v[i] + B[i-1][j - w[i]];
                else
                    B[i][j] = B[i-1][j];
            }
            else
            {
                B[i][j] = B[i-1][j];
            }
        }
    }

    cout << "\nMaximum Profit : " << B[n][W] << endl;

    //selected items
    cout << "\nSelected items:\n";

    int i = n, j = W;

    while(i > 0 && j > 0){
        if(B[i][j] != B[i-1][j]){
            cout << "Item " << i 
                 << " (Weight=" << w[i] 
                 << ", Profit=" << v[i] << ")\n";

            j = j - w[i];  
        }
        i--; 
    }

    // print table
    cout << "\nTable:\n";
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}