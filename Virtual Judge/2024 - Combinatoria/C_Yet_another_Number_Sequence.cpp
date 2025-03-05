#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int periods[] = {0, 60, 300, 1500, 15000};

vector<vector<ll>> multiplix_matrix(vector<vector<ll>> matrix_a, vector<vector<ll>> matrix_b, ll mod) {
    return {
        {
            (matrix_a[0][0] * matrix_b[0][0] + matrix_a[0][1] * matrix_b[1][0]) % mod,
            (matrix_a[0][0] * matrix_b[0][1] + matrix_a[0][1] * matrix_b[1][1]) % mod
        },
        {
            (matrix_a[1][0] * matrix_b[0][0] + matrix_a[1][1] * matrix_b[1][0]) % mod,
            (matrix_a[1][0] * matrix_b[0][1] + matrix_a[1][1] * matrix_b[1][1]) % mod
        }
    };
}

vector<vector<ll>> pow_matrix(vector<vector<ll>> matrix, ll n, ll mod) {
    vector<vector<ll>> result = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n % 2 == 1) {
            result = multiplix_matrix(result, matrix, mod);
        }
        matrix = multiplix_matrix(matrix, matrix, mod);
        n /= 2;
    }
    return result;
}

ll fibonacci_mod(ll n, ll a, ll b, ll mod) {
    if (n == 0) return a % mod;
    if (n == 1) return b % mod;
    vector<vector<ll>> matrix = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = pow_matrix(matrix, n - 1, mod);
    return (result[0][0] * b + result[0][1] * a) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    while (cases--) {
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        ll mod = 1;
        for (int i = 0; i < m; i++) {
            mod *= 10;
        }
        ll period = periods[m];
        n %= period;
        cout << fibonacci_mod(n, a, b, mod) << endl;
    }
    return 0;
}