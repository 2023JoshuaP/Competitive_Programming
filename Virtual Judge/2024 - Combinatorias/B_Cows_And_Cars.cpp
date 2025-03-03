#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ncows, ncars, nshow;
    while (cin >> ncows >> ncars >> nshow) {
        double ans = (double(ncows) / (ncows + ncars)) * (double(ncars) / (ncows + ncars - nshow - 1)) + (double(ncars) / (ncows + ncars)) * (double(ncars - 1) / (ncows + ncars - nshow - 1));
        cout << fixed << setprecision(5) << ans << '\n';
    }
    return 0;
}