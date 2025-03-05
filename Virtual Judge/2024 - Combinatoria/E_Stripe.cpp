#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(int N, int K) {
    if (K > N) return 0;
    if (K == 0 || K == N) return 1;
    ll res = 1;
    for (int i = 1; i <= K; i++) {
        res = res * (N - i + 1) / i;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, K, sum_black = 0;
        cin >> N >> K;
        vector<int> code(K);
        for (int i = 0; i < K; i++) {
            cin >> code[i];
            sum_black += code[i];
        }
        int space_min = sum_black + (K - 1);
        int space_rest = N - space_min;
        if (space_rest < 0) {
            cout << 0 << '\n';
        }
        else {
            cout << solve(space_rest + K, K) << '\n';
        }
    }
    return 0;
}