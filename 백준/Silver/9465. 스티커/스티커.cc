#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; ++i) {
		int row;
		cin >> row;

		vector<vector<int>> board;
		vector<vector<int>> dp;
		vector<int> col;
		col.resize(row, 0);
		board.resize(2, col);
		dp.resize(2, col);
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < row; ++k)
				cin >> board[j][k];
		}
		if (row == 1)
			cout << max(board[0][0], board[1][0]) << endl;
		else {
			dp[0][0] = board[0][0];
			dp[1][0] = board[1][0];
			for (int j = 1; j < row; ++j) {
				dp[0][j] = max(dp[0][j - 1], dp[1][j - 1] + board[0][j]);
				dp[1][j] = max(dp[1][j - 1], dp[0][j - 1] + board[1][j]);
			}
			cout << max(dp[0][row - 1], dp[1][row - 1]) << endl;
		}
	}

	return 0;
}