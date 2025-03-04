#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fib(1001, vector<int>(301, 0));

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fib[0][0] = 1;
    fib[1][0] = 2;
    for (int i = 2; i < 1001; i++) {
        for (int j = 0; j < 301; j++) {
            fib[i][j] = fib[i - 1][j] + fib[i - 2][j];
        }
        for (int j = 0; j < 301; j++) {
            fib[i][j + 1] += fib[i][j] / 10;
            fib[i][j] %= 10;
        }
    }
    int num;
    while (cin >> num) {
        int position = 299;
        while (fib[num][position] == 0 && position > 0) {
            position--;
        }
        for (int i = position; i >= 0; i--) {
            cout << fib[num][i];
        }
        cout << '\n';
    }
    return 0;
}