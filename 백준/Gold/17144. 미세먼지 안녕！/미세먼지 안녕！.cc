#include <iostream>
#include <vector>

using namespace std;

struct airclean {
	vector<pair<int, int>> a;
};

void dust(int r, int c, vector<vector<int>>&, vector<vector<int>>&);
void airMove(int r, int c, bool isUp, vector<vector<int>>& board);

int main() {

	int r, c, t;
	cin >> r >> c >> t;
	vector<vector<int>> board;
	airclean a;
	for (int i = 0; i < r; ++i) {
		vector<int> temp;
		for (int j = 0; j < c; ++j) {
			int q;
			cin >> q;
			if (q == -1)
				a.a.push_back({ i, j });
			temp.push_back(q);
		}
		board.push_back(temp);
	}
	
	for (int i = 0; i < t; ++i) {
		// 확산 페이즈
		// nextBoard 하나 만들어서 적용 후 board에 복붙
		vector<vector<int>> nextBoard;
		vector<int> temp;
		temp.resize(c, 0);
		nextBoard.resize(r, temp);
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < c; ++k) {
				if (board[j][k] != 0)
					dust(j, k, board, nextBoard);
			}
		}
		board = nextBoard;

		// 공기청정기 페이즈
		// 위는 우 위 왼 아래
		// 아래는 우 아해 왼 위 순으로 차례대로 이동
		// while문으루다가 벽만나면 방향 이동
		airMove(a.a[0].first, a.a[0].second, true, board);
		airMove(a.a[1].first, a.a[1].second, false, board);
	}
	int ans = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (board[i][j] > 0)
				ans += board[i][j];
		}
	}
	cout << ans;
	
	return 0;
}

void dust(int r, int c, vector<vector<int>>& board, vector<vector<int>>& newBoard) {
	if (board[r][c] == -1) {
		newBoard[r][c] = -1;
		return;
	}
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int nPosDust = board[r][c];
	if (nPosDust / 5 > 0) {
		int sepDust = nPosDust / 5;
		for (int i = 0; i < 4; ++i) {
			int nx = r + dx[i];
			int ny = c + dy[i];
			if (0 <= nx && nx < board.size()
				&& 0 <= ny && ny < board[0].size()
				&& board[nx][ny] != -1) {
				newBoard[nx][ny] += sepDust;
				nPosDust -= sepDust;
			}
		}
	}
	newBoard[r][c] += nPosDust;
}

void airMove(int r, int c, bool isUp, vector<vector<int>>& board) {
	int dx[4] = { 0, -1, 0, 1 };
	int dy[4] = { 1, 0, -1, 0 };
	if (!isUp) {
		dx[1] = 1; 
		dx[3] = -1;
	}
	int idx = 0;
	int prev = 0;
	while (idx < 4) {
		int nx = r + dx[idx];
		int ny = c + dy[idx];
		if (nx >= 0 && nx < board.size()
			&& ny >= 0 && ny < board[0].size()
			&& board[nx][ny] != -1) {
			int temp = board[nx][ny];
			board[nx][ny] = prev;
			prev = temp;
			r = nx;
			c = ny;
		}
		else
			++idx;
	}
}