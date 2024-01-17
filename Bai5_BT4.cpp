#include <bits/stdc++.h>
using namespace std;

const int maxn = 10003;

long long dp[maxn][maxn];

int main() {
    int n; cin >> n;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[n][i];
    }
    cout << ans;
}