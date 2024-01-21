#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> schedule;
	vector<int> dp;
	dp.resize(n+1);
	for (int i = 0; i < n; ++i) {
		int t, p;
		cin >> t >> p;
		schedule.push_back({ t, p });
	}
	for (int i = 0; i < n; ++i) {
		for(int j = i+schedule[i].first; j < n + 1; ++j){
            if(dp[j] < dp[i] + schedule[i].second)
                dp[j] = dp[i] + schedule[i].second;
        }
	}
	cout << dp[n];
	return 0;
}