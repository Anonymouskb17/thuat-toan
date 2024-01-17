#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll f[1000001];

void gen(int n) {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
}

char g(int n, int m) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (m > f[n-2]) return g(n-1, m-f[n-2]);
    return g(n-2, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    gen(n);
    cout << g(n, m);
}