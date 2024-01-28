#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y, char tar, vector<string>& b);

int main() {
	
	vector<string> Nboard;
	vector<string> RGboard;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string inp;
		cin >> inp;
		Nboard.push_back(inp);
	}

	// 적록색약 보드 생성
	for (int i = 0; i < n; ++i) {
		string temp = "";
		for (int j = 0; j < n; ++j) {
			if (Nboard[i][j] == 'R')
				temp += 'G';
			else
				temp += Nboard[i][j];
		}
		RGboard.push_back(temp);
	}

	// 보드 각각 bfs돌면서 구역 구하기
	int Nans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (Nboard[i][j] != 'X') {
				bfs(i, j, Nboard[i][j], Nboard);
				Nans += 1;
			}
		}
	}
	
	int RGans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (RGboard[i][j] != 'X') {
				bfs(i, j, RGboard[i][j], RGboard);
				RGans += 1;
			}
		}
	}

	cout << Nans << " " << RGans;
}

void bfs(int x, int y, char tar, vector<string>& b) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	b[x][y] = 'X';
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			pair<int, int> next = { now.first + dx[i], now.second + dy[i] };
			if (next.first >= 0 && next.first < n &&
				next.second >= 0 && next.second < n && b[next.first][next.second] == tar) {
				q.push(next);
				b[next.first][next.second] = 'X';
			}
		}
	}
}