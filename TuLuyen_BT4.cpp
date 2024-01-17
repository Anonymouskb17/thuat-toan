#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 1;

void solve() {
    long long f[4] = {0, 1, 1, 2};
    if (n <= 4) {
        ans = f[n-1];
        return;
    }
    for (int i = 5; i <= n; ++i) {
        ans = f[0] + f[1] + f[2];
        f[0] = f[1];
        f[1] = f[2];
        f[2] = f[3];
        f[3] = ans;
    }
}

int main() {
    cin >> n;
    solve();
    cout << ans;
}