#include <iostream>
#include <vector>

using namespace std;

void dfs(int r, int c, vector<vector<int>>& board, int cnt, int sum, vector<vector<int>>& visited);

int ans = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>> board;
	vector<vector<int>> visited;
	vector<int> row;
	row.resize(c, 0);
	board.resize(r, row);
	visited.resize(r, row);


	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j)
			cin >> board[i][j];
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			visited[i][j] = 1;
			dfs(i, j, board, 1, board[i][j], visited);
			visited[i][j] = 0;
		}
	}
	cout << ans;
}

void dfs(int r, int c, vector<vector<int>>& board, int cnt, int sum, vector<vector<int>>& visited) {
	if (cnt == 4) {
		if (ans < sum)
			ans = sum;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = r + dx[i];
		int ny = c + dy[i];

		if (0 <= nx && nx < board.size()
			&& 0 <= ny && ny < board[0].size()
			&& visited[nx][ny] != 1) {
			if (cnt == 2) {
				visited[nx][ny] = 1;
				dfs(r, c, board, cnt + 1, sum + board[nx][ny], visited);
				visited[nx][ny] = 0;
			}
			
			visited[nx][ny] = 1;
			dfs(nx, ny, board, cnt + 1, sum + board[nx][ny], visited);
			visited[nx][ny] = 0;
		}
	}
}