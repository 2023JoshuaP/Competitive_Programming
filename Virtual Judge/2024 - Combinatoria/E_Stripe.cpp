#include <bits/stdc++.h>
using namespace std;

int N, K, T, a;
string combination[201][201];

string solve(const string &N, const string &K) {
    int n = N.size(), k = K.size();
    string res(max(n, k), '0');
    bool carry = false;
    for (int i = 0; i < res.size(); i++) {
        int sum = carry;
        if (i < n) sum += N[n - 1 - i] - '0';
        if (i < k) sum += K[k - 1 - i] - '0';
        carry = sum > 9;
        res[res.size() - 1 - i] = (sum % 10) + '0';
    }
    if (carry) res.insert(res.begin(), '1');
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 201; i++) {
        combination[i][0] = "1";
        for (int j = 1; j <= i; j++) {
            if (i - j < j) {
                combination[i][j] = combination[i][i - j];
                continue;
            }
            combination[i][j] = solve(combination[i - 1][j], combination[i - 1][j - 1]);
        }
    }
    cin >> T;
    while (T--) {
        cin >> N >> K;
        int blank = N;
        for (int i = 0; i < K; i++) {
            cin >> a;
            blank -= a;
        }
        blank -= K - 1;
        cout << (blank < 0 ? "0" : combination[blank + K][min(blank, K)]) << "\n";
    }
    return 0;
}