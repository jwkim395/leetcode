#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main() {
	int target, n;
	cin >> target;
	cin >> n;
	vector<int> remote;
	remote.resize(10, 0);
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		remote[temp] = 1;
	}
	int ans = abs(target - 100);
	for (int i = 0; i < 1000001; ++i) {
		string a = to_string(i);
		int cnt = a.length();
		bool flag = true;
		for (int i = 0; i < cnt; ++i) {
			if (remote[a[i] - '0'] == 1) {
				flag = false;
				break;
			}
		}
		if (flag)
			ans = min(ans, abs(target - i) + cnt);
	}
	cout << ans;
}