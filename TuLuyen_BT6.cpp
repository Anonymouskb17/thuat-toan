#include <bits/stdc++.h>
using namespace std;

vector<int> a(100, 0);
int cnt = 0, n, m;

void subarr(int sum, int idx){
    // check = false;
    int tmp = sum + (n - idx) * a[idx + 1];
	if (idx > n || tmp < m) {
		return;
	}
    if (sum > m) {
        ++cnt;
    }
	for (int i = idx + 1; i <= n; ++i){
		subarr(sum + a[i], i);
	}
}

int main() {
    cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
    sort(a.begin() + 1, a.begin() + n + 1, greater<int>());
	subarr(0, 0);
    cout << cnt;
}