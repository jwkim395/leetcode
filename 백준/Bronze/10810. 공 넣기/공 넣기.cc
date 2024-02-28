#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	vector<int> basket(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		int j, k, l;
		cin >> j >> k >> l;
		for (int row = j; row <= k; ++row)
			basket[row] = l;
	}
	for (int i = 1; i <= n; ++i)
		cout << basket[i] << " ";

	return 0;
}