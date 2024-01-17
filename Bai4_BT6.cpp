#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int b[n];
    b[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) b[i] = b[i - 1];
        else b[i] = b[i - 1] + 1;
    }
    // for (auto x : b) cout << x << " ";
    int m = b[n-1] + 1;
    if (m == 1) {
        cout << 0;
        return 0;
    }
    if (k >= m) {
        cout << 0;
        return 0;
    }
    cout << 1;
}