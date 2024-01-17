#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 1;

void solve() {
    long long f[3] = {0, 1, 1};
    if (n <= 3) {
        ans = f[n-1];
        return;
    }
    for (int i = 4; i <= n; ++i) {
        ans = f[0] + f[1];
        f[0] = f[1];
        f[1] = f[2];
        f[2] = ans;
    }
}

int main() {
    cin >> n;
    solve();
    cout << ans;
}