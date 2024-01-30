#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	int n, m;
	int ans = 0;
	cin >> n >> m;
	vector<string> board;
	for (int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		board.push_back(temp);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'I') {
				queue<pair<int, int>> q;
				q.push({ i, j });
				board[i][j] = 'E';
				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();
					for (int r = 0; r < 4; ++r) {
						pair<int, int> next = now;
						next.first += dx[r];
						next.second += dy[r];

						if (next.first >= 0 && next.first < n
							&& next.second >= 0 && next.second < m
							&& board[next.first][next.second] != 'E'
							&& board[next.first][next.second] != 'X') {
							if (board[next.first][next.second] == 'P')
								ans += 1;
							board[next.first][next.second] = 'E';
							q.push(next);
						}
					}
				}
				break;
			}
		}
	}
	if (ans == 0)
		cout << "TT";
	else
		cout << ans;
	return 0;
}