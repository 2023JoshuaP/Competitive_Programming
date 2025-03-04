#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> fibonacci() {
    vector<int> fib = {1, 2};
    while (fib.back() <= 1e9) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }
    return fib;
}

ll fibinary_to_decimal(string& fibinary, vector<int>& fib) {
    ll decimal = 0;
    for (int i = 0; i < fibinary.size(); i++) {
        if (fibinary[fibinary.size() - 1 - i] == '1') {
            decimal += fib[i];
        }
    }
    return decimal;
}

string decimal_to_fibinary(ll num, vector<int>& fib) {
    string fibinary;
    bool started = false;
    for (int i = fib.size() - 1; i >= 0; i--) {
        if (fib[i] <= num) {
            num -= fib[i];
            fibinary += '1';
            started = true;
        }
        else if (started) {
            fibinary += '0';
        }
    }
    return fibinary.empty() ? "0" : fibinary;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> fib = fibonacci();
    string fibinary1, fibinary2;
    bool first = true;
    while (cin >> fibinary1 >> fibinary2) {
        if (!first) {
            cout << '\n';
        }
        first = false;
        ll decimal1 = fibinary_to_decimal(fibinary1, fib);
        ll decimal2 = fibinary_to_decimal(fibinary2, fib);
        cout << decimal_to_fibinary(decimal1 + decimal2, fib) << '\n';
    }
    return 0;
}