#include <iostream>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[50], val[50];

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter values (profits):\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int dp[51][101];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                int include = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int exclude = dp[i - 1][w];

                if (include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nProfit Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    cout << "\nTotal Maximum Profit = " << dp[n][W];

    return 0;
}