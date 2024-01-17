#include <bits/stdc++.h>
using namespace std;

map<long long, long long> mp;

long long f(long long n) {
    if (n == 1) return 0;
    if (mp[n]) return mp[n];
    if (n & 1) {
        mp[n] = f(3 * n + 1) + 1;
    } else {
        mp[n] = f(n / 2) + 1;
    }
    return mp[n];
}

int main() {
    long long n;
    cin >> n;
    cout << f(n);
}