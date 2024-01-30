#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int comNum, connectNum;
	vector<vector<int>> board;
	cin >> comNum;
	cin >> connectNum;
	vector<int> col;
	board.resize(comNum, col);
	for (int i = 0; i < connectNum; ++i) {
		int st, end;
		cin >> st >> end;
		board[st - 1].push_back(end - 1);
		board[end - 1].push_back(st - 1);
	}
	
	int ans = 0;
	queue<int> q;
	vector<int> visited;
	visited.resize(comNum, 0);
	visited[0] = 1;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < board[now].size(); ++i) {
			if (visited[board[now][i]] == 0) {
				visited[board[now][i]] = 1;
				q.push(board[now][i]);
				ans += 1;
			}
		}
	}
	cout << ans;
	return 0;
}