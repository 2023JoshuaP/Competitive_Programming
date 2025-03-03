#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double p;
    while (cin >> n >> p, n != 0) {
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (i - 1 == j) {
                    dp[i][j] = 1 - pow(p, i);
                }
                else {
                    double expected = dp[i - j - 2][j];
                    double winning = pow(p, j + 1);
                    dp[i][j] = dp[i - 1][j] - expected * (1 - p) * winning;
                }
            }
        }
        double expected_value = 0.0;
        for (int i = 1; i <= n; i++) {
            expected_value += (dp[n][i] - dp[n][i - 1]) * i;
        }
        cout << fixed << setprecision(6) << expected_value << "\n";
    }
    return 0;
}