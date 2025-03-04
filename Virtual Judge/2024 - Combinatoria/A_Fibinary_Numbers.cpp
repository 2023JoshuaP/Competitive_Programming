#include <bits/stdc++.h>
using namespace std;

string sum_fibinary(string fibinary1, string fibinary2) {
    string result;
    int carry = 0;
    for (int i = 0; i < max(fibinary1.size(), fibinary2.size()); i++) {
        int sum = carry;
        if (i < fibinary1.size()) {
            sum += fibinary1[i] - '0';
        }
        if (i < fibinary2.size()) {
            sum += fibinary2[i] - '0';
        }
        result.push_back(sum % 2 + '0');
        carry = sum / 2;
    }
    if (carry) {
        result.push_back(carry + '0');
    }
    return result;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string fibinary1, fibinary2;
    while (getline(cin, fibinary1) && getline(cin, fibinary2)) {
        string sum = sum_fibinary(fibinary1, fibinary2);
        cout << sum << '\n';
        string blank;
        if (getline(cin, blank) && blank.empty()) {
            cout << '\n';
        }
    }
    return 0;
}