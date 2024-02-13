#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pipe {
	int row;
	int col;
	int dir;
};

int main() {

	int n;
	cin >> n;

	vector<vector<int>> board;
	vector<int> temp;
	temp.resize(n, 0);
	board.resize(n, temp);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int t;
			cin >> t;
			if (t == 1)
				board[i][j] = -1;
			else
				board[i][j] = 0;
		}
	}
	
	board[0][1] = 1;
	queue<pipe> q;
	q.push({ 0, 1, 0 });
	int dx[3] = { 0, 1, 1 };
	int dy[3] = { 1, 1, 0 };

	while (!q.empty()) {
		pipe now = q.front();
		q.pop();
		if (now.dir == 0) {
			for (int i = 0; i < 2; ++i) {
				int nx = now.row + dx[i];
				int ny = now.col + dy[i];

				if (i % 2 == 0) {
					if (0 <= nx && nx < n
						&& 0 <= ny && ny < n
						&& board[nx][ny] != -1) {
						board[nx][ny] += 1;
						q.push({ nx, ny, i });
					}
				}
				else {
					if (0 <= nx && nx < n
						&& 0 <= ny && ny < n
						&& board[nx][ny] != -1
						&& board[nx][now.col] != -1
						&& board[now.row][ny] != -1) {
						board[nx][ny] += 1;
						q.push({ nx, ny, i });
					}
				}
				
			}
		}
		else if (now.dir == 1) {
			for (int i = 0; i < 3; ++i) {
				int nx = now.row + dx[i];
				int ny = now.col + dy[i];

				if (i % 2 == 0) {
					if (0 <= nx && nx < n
						&& 0 <= ny && ny < n
						&& board[nx][ny] != -1) {
						board[nx][ny] += 1;
						q.push({ nx, ny, i });
					}
				}
				else {
					if (0 <= nx && nx < n
						&& 0 <= ny && ny < n
						&& board[nx][ny] != -1
						&& board[nx][now.col] != -1
						&& board[now.row][ny] != -1) {
						board[nx][ny] += 1;
						q.push({ nx, ny, i });
					}
				}
			}
		}
		else if (now.dir == 2) {
			for (int i = 1; i < 3; ++i) {
				int nx = now.row + dx[i];
				int ny = now.col + dy[i];

				if (i % 2 == 0) {
					if (0 <= nx && nx < n
						&& 0 <= ny && ny < n
						&& board[nx][ny] != -1) {
						board[nx][ny] += 1;
						q.push({ nx, ny, i });
					}
				}
				else {
					if (0 <= nx && nx < n
						&& 0 <= ny && ny < n
						&& board[nx][ny] != -1
						&& board[nx][now.col] != -1
						&& board[now.row][ny] != -1) {
						board[nx][ny] += 1;
						q.push({ nx, ny, i });
					}
				}
			}
		}
	}
	if (board[n - 1][n - 1] == -1)
		cout << 0;
	else
		cout << board[n - 1][n - 1];
	return 0;
}