#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> is_prime_range(int x, int y) {
    vector<int> primes;
    for (int i = x; i <= y; i++) {
        if (is_prime(i)) primes.push_back(i);
    }
    return primes;
}

void find_determinate_primes(int x, int y) {
    vector<int> primes = is_prime_range(x, y);
    if (primes.size() < 3) {
        return;
    }
    vector<vector<int>> result;
    vector<int> temp = {primes[0]};
    for (int i = 1; i < primes.size(); i++) {
        int diff = primes[i] - primes[i - 1];
        if (temp.size() >= 2 && (primes[i - 1] - temp[temp.size() - 2]) != diff) {
            if (temp.size() >= 3) {
                result.push_back(temp);
            }
            temp = {primes[i - 1], primes[i]};
        }
        else {
            temp.push_back(primes[i]);
        }
    }
    if (temp.size() >= 3) {
        result.push_back(temp);
    }
    for (auto& seq : result) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    while (cin >> x >> y && (x || y)) {
        if (x > y) swap(x, y);
        find_determinate_primes(x, y);
    }
    return 0;
}