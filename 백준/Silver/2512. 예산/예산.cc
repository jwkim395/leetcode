#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> reg;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		reg.push_back(temp);
	}
	int m;
	cin >> m;
	int l = 0;
	int r = *max_element(reg.begin(), reg.end());
	int maxi = 0;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (reg[i] < mid)
				cur += reg[i];
			else
				cur += mid;
		}
		if (maxi < cur && cur <= m) {
			maxi = cur;
			ans = mid;
		}
		if (cur < m)
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans;

	return 0;
}