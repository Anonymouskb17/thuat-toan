#include <bits/stdc++.h>
using namespace std;

int main() {
    int p; cin >> p;
    long long res = 0;
    for (int n = 1; n * n <= p; ++n) {
        for (int m = 1 + n ; m * m <= p; ++m) {
            if (m * m + 2 * m * n > p) break;
            if ((m + n) % 2 == 0 || __gcd(m, n) != 1) continue;
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;
            res += p / (a + b + c);
        }
    }
    cout << res;
}