#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>&, int, int);

int main() {

	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; ++i) {
		int r, c, q;
		cin >> r >> c >> q;
		vector<vector<int>> board;
		vector<int> col;
		col.resize(c, 0);
		board.resize(r, col);
		for (int j = 0; j < q; ++j) {
			int a, b;
			cin >> a >> b;
			board[a][b] = 1;
		}
		int ans = 0;
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < c; ++k) {
				if (board[j][k] == 1) {
					bfs(board, j, k);
					ans += 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

void bfs(vector<vector<int>>& b, int r, int c) {
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	b[r][c] = 0;
	queue<pair<int, int>> q;
	q.push({ r, c });
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (0 <= nx && nx < b.size()
				&& 0 <= ny && ny < b[0].size()
				&& b[nx][ny] == 1) {
				b[nx][ny] = 0;
				q.push({ nx, ny });
			}
		}
	}
}