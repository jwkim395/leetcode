#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> obj;
	obj.push_back({ 0, 0 });
	for (int i = 0; i < n; ++i) {
		int w, v;
		cin >> w >> v;
		obj.push_back({ w, v });
	}
	vector<int> temp(k + 1, 0);
	vector<vector<int>> bag(n + 1, temp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			int w = obj[i].first;
			int v = obj[i].second;
			if (w > j)
				bag[i][j] = bag[i - 1][j];
			else
				bag[i][j] = max(v + bag[i - 1][j - w], bag[i - 1][j]);
		}
	}
	cout << bag[n][k];
	return 0;
}