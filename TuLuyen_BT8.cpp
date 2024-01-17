#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;

void pt(int sum, int idx, int maxnum, vector<int> a, long long tich) {
	if (sum == n && tich >= k) {
		++cnt;
		return;
	}
	else if (sum > n) {
		return;
	}
	else {
		for (int i = maxnum; i > 0; --i) {
			a[idx] = i;
			pt(sum + i, idx - 1, i, a, tich * i);
		}
	}
}

int main() {
//	cout << ((9 == 5) == 0) << "\n";
	cout << "N = "; cin >> n;
	cout << "K = "; cin >> k;
	vector<int> a(n + 1, 0);
//	for (int i = 0; i < n; ++i) a[i] = 0;
	pt(0, n, n, a, 1);
    cout << "So cach phan tich cap K = " << cnt;
}
