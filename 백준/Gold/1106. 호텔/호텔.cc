#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int c, n;
	cin >> c >> n;
	vector<pair<int, int>> cities;
	
	vector<int> dp(100001, 0);

	for (int i = 1; i <= n; ++i) {
		int price, customer;
		cin >> price >> customer;
		cities.push_back({price, customer});
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= 100000; ++j) {
			if (j - cities[i].first >= 0) {
				dp[j] = max(dp[j - cities[i].first] + cities[i].second, dp[j]);
			}
		}
	}
	for (int i = 1; i <= 100000; ++i) {
		if (dp[i] >= c) {
			cout << i;
			break;
		}
	}

	return 0;
}