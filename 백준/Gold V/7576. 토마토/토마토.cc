#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tomato {
	int x;
	int y;
	int cnt;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	int c, r;
	cin >> c >> r;
	vector<int> row(c, 0);
	vector<vector<int>> board(r, row);
	queue<tomato> q;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push({ i, j, 0 });
		}
	}
	int ans = 0;
	while (!q.empty()) {
		tomato now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (0 <= nx && nx < r
				&& 0 <= ny && ny < c
				&& board[nx][ny] == 0) {
				board[nx][ny] = 1;
				q.push({ nx, ny, now.cnt + 1 });
				if (ans < now.cnt + 1) {
					ans = now.cnt + 1;
				}
			}
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (board[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}