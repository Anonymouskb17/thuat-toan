#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1003;

int val[maxn][maxn];
int m, n;
ll dp[maxn][maxn];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> val[i][j];
        }
        val[i][n + 1] = val[i][0] = 1e9;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + val[i][j];
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[m][i]);
    }
    cout << ans;
}