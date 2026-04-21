#include <iostream>
#include <cmath>
using namespace std;

int x[20];
bool place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    cout << "\nSolution (Array form): ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << "\nBoard:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
}

void NQueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;

            if (k == n) {
                printSolution(n);
            } else {
                NQueen(k + 1, n);
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    NQueen(1, n);
    return 0;
}