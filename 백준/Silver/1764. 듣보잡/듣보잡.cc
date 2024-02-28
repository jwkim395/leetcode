#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	map<string, int> mem;
	vector<string> ans;
	for (int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		mem[temp] = 1;
	}
	for (int i = 0; i < m; ++i) {
		string temp;
		cin >> temp;
		if (mem[temp] >= 1)
			ans.push_back(temp);
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
	return 0;
}