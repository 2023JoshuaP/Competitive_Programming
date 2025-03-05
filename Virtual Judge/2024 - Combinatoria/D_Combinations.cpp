#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mem[101][101];

ll solve(int N, int K) {
    if (K == 0) return 1;
    if (N == K) return 1;
    if (mem[N][K] != -1)
        return mem[N][K]; 
    mem[N][K] = solve(N - 1, K) + solve(N - 1, K - 1);
    return mem[N][K];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    memset(mem, -1, sizeof(mem));
    while (cin >> N >> K && N != 0 && K != 0) {
        cout << N << " things taken " << K << " at a time is " << solve(N, K) << " exactly." << '\n';
    }
    return 0;
}