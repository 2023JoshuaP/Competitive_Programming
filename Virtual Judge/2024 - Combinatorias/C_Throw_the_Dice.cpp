/* Codigo hecho en Linux, se recomienda el uso de la libreria BOOST para manejar numeros mas grandes */

#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int F, N, S;
    while (cin >> F >> N >> S) {
        cpp_int denom = 1;
        for (int i = 0; i < N; i++) {
            denom *= F;
        }
        if (N == 0) {
            cout << (S == 0 ? "1/1\n" : "0/1\n");
            continue;
        }
        if (S < N || S > N * F) {
            cout << "0/" << denom << "\n";
            continue;
        }
        int maxSum = N * F;
        vector<cpp_int> dp_prev(maxSum + 1, 0), dp_curr(maxSum + 1, 0);
        dp_prev[0] = 1;
        for (int dice = 1; dice <= N; dice++) {
            cpp_int window_sum = 0;
            for (int s = dice; s <= dice * F; s++) {
                window_sum += (s - 1 >= dice - 1) ? dp_prev[s - 1] : 0;
                if (s - F - 1 >= dice - 1) window_sum -= dp_prev[s - F - 1];
                dp_curr[s] = window_sum;
            }
            swap(dp_prev, dp_curr);
            fill(dp_curr.begin(), dp_curr.end(), 0);
        }
        cout << dp_prev[S] << "/" << denom << "\n";
    }
    return 0;
}