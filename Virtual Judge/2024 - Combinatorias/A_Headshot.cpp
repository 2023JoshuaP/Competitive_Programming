#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (getline(cin, s)) {
        int longitude = s.size();
        int cont = 0, changes = 0;
        for (int i = 0; i < longitude; i++) {
            if (s[i] == '0') {
                if (s[(i + 1) % longitude] == '0') {
                    cont++;
                }
                changes++;
            }
        }
        if (cont * longitude == changes * changes) {
            cout << "EQUAL\n";
        }
        else if (cont * longitude > changes * changes) {
            cout << "SHOOT\n";
        }
        else {
            cout << "ROTATE\n";
        }
    }
    return 0;
}