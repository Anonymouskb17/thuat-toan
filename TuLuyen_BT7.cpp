#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1e9

string s;
ll dp[1003];
map<char, int> lastIndex;

void solve() {
    dp[0] = 0;
    dp[1] = 1;
    lastIndex[s[0]] = 1;
    for (int i = 2; i <= s.length(); ++i) {
        if (lastIndex[s[i - 1]] == 0) {
            dp[i] = (dp[i - 1] * 2 + 1) % (ll)MOD;
        } else {
            dp[i] = ((dp[i - 1] + (ll)MOD) * 2 - dp[lastIndex[s[i - 1]] - 1]) % (ll)MOD;
        }
        lastIndex[s[i - 1]] = i;
    }
    cout << dp[s.length()];
}

int main() {
    cin >> s;
    solve();
}