#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int S;
    cin >> S;
    while (S--) {
        int n, i;
        float p;
        cin >> n >> p >> i;
        if (p == 0) {
            cout << "0.0000\n";
            continue;
        }
        double first = pow(1.0 - p, i - 1) * p;
        double second = pow(1.0 - p, n);
        double ans = first / (1.0 - second);
        cout << fixed << setprecision(4) << ans << "\n";
    }
    return 0;
}