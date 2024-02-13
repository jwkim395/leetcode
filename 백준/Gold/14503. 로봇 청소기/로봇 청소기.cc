#include <iostream>
#include <vector>

using namespace std;

bool chk4Dir(vector<vector<int>>& b, int row, int col);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	int row, col;
	cin >> row >> col;
	vector<vector<int>> board;
	vector<int> temp;
	temp.resize(col, 0);
	board.resize(row, temp);

	int x, y, d;
	cin >> x >> y >> d;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			cin >> board[i][j];
	}

	int ans = 0;

	while (true) {
		// 현재 칸 청소 x
		if (board[x][y] == 0) {
			board[x][y] = -1;
			ans += 1;
		}
		else {
			// 주변 4칸 빈칸 체크
			if (!chk4Dir(board, x, y)) {
				int nx = x + dx[(d + 2) % 4];
				int ny = y + dy[(d + 2) % 4];
				// 없으면 방향 유지 후 1칸 후진
				if (0 <= nx && nx < row
					&& 0 <= ny && ny < col
					&& board[nx][ny] != 1) {
					x = nx;
					y = ny;
				}
				// 후진 못하면 break
				else
					break;
			}
			else {
				// 있으면 반시계 방향 회전 후 정면 확인
				// 정면 청소 x면 전진
				d -= 1;
				if (d < 0)
					d += 4;
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (0 <= nx && nx < row
					&& 0 <= ny && ny < col
					&& board[nx][ny] == 0) {
					x = nx;
					y = ny;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

bool chk4Dir(vector<vector<int>>& b, int row, int col) {
	for (int i = 0; i < 4; ++i) {
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (0 <= nx && nx < b.size()
			&& 0 <= ny && ny < b[0].size()
			&& b[nx][ny] == 0)
			return true;
	}
	return false;
}