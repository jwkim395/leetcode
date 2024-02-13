#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v;
	v.resize(100001, 100000);
	v[n] = 0;
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	int ans = 0;
	int less = INT_MAX;
	if (n == k) {
		ans = 1;
	}
	else {
		while (q.size() > 0) {
			pair<int, int> now = q.front();
			q.pop();
			int nextDir[3] = { 1, -1, now.first };
			for (int i = 0; i < 3; ++i) {
				int next = now.first + nextDir[i];
				if (next >= 0 && next <= 100000 && v[next] >= v[now.first] + 1) {
					v[next] = v[now.first] + 1;
					if (k == next && less >= now.second + 1) {
						less = now.second + 1;
						ans += 1;
					}
					q.push({ next, now.second + 1 });
				}
			}
		}
	}
	cout << v[k] << endl;
	cout << ans;

	return 0;
}