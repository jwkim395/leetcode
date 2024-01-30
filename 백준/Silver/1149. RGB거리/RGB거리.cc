#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> board;
	vector<vector<int>> dp;
	for (int i = 0; i < n; ++i) {
		int r, g, b;
		cin >> r >> g >> b;
		vector<int> temp;
		temp.resize(3, 0);
		dp.push_back(temp);
		temp[0] = r;
		temp[1] = g;
		temp[2] = b;
		board.push_back(temp);
	}
	dp[0][0] = board[0][0];
	dp[0][1] = board[0][1];
	dp[0][2] = board[0][2];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j) 
			dp[i][j] = board[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
	}
	cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
	return 0;
}