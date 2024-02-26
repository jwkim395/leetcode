#include <iostream>
#include <vector>

using namespace std;

int main() {

	int t;
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> dp;
		dp.resize(10, 1);
		for (int i = 1; i < n; ++i) {
			vector<int> temp(dp);
			dp[0] = temp[7] % 1234567;
			dp[1] = (temp[2] + temp[4]) % 1234567;
			dp[2] = (temp[1] + temp[3] + temp[5]) % 1234567;
			dp[3] = (temp[2] + temp[6]) % 1234567;
			dp[4] = (temp[1] + temp[5] + temp[7]) % 1234567;
			dp[5] = (temp[2] + temp[4] + temp[6] + temp[8]) % 1234567;
			dp[6] = (temp[3] + temp[5] + temp[9]) % 1234567;
			dp[7] = (temp[4] + temp[8] + temp[0]) % 1234567;
			dp[8] = (temp[5] + temp[7] + temp[9]) % 1234567;
			dp[9] = (temp[6] + temp[8]) % 1234567;
		}
		int ans = 0;
		for (int i = 0; i < 10; ++i) {
			ans += (dp[i] % 1234567);
		}
		cout << ans % 1234567 << endl;
	}
	return 0;
}
