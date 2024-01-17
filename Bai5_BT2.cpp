#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    long long dp[a.size() + 1][b.size() + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[0][1] = dp[1][0] = 0;
    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
        cout << dp[i][b.size()] << "\n";
    }
    if (a.size() >= b.size()) {
        cout << a.size() - dp[a.size()][b.size()];
    }
    else {
        cout << b.size() - dp[a.size()][b.size()];
    }
}