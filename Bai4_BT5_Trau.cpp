#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

vector<pii> points;

long long squared_dist(pii a, pii b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + 
           (a.se - b.se) * (a.se - b.se);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        points.push_back({x, y});
    }
    long long res = squared_dist(points[0], points[1]);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            res = min(res, squared_dist(points[i], points[j]));
        }
    }
    cout << res;
}