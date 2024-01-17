#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

int main() {
    int n; cin >> n;
    vector<pii> a(n);
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi >> a[i].se;
        mp[a[i].fi] = 0;
        st.insert(a[i].fi);
    }
    sort(a.begin(), a.end(), [](pii p1, pii p2) {
        return p1.se > p2.se;
    });
    // for (int i = 0; i < n; ++i) {
    //     cout << a[i].fi << " " << a[i].se << "\n";
    // }
    for (int i = 0; i < n; ++i) {
        int x = a[i].fi;
        int y = a[i].se;
        auto it  = st.lower_bound(x);
        while (mp[*it] != 0 && it != st.begin()) {
            it--;
        }
        if (it == st.begin() && mp[*it] != 0) {
            continue;
        }
        mp[*it] = y;
    }
    int ans = 0;
    for (auto x : mp) {
        ans += x.se;
    }
    cout << ans;
}