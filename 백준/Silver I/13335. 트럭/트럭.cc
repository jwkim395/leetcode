#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, l, w;
	cin >> n >> l >> w;
	queue<int> trucks;
	queue<int> bridge;
	for (int i = 0; i < l; ++i)
		bridge.push(0);
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		trucks.push(temp);
	}

	int ans = 0;
	while (!trucks.empty()) {
		w += bridge.front();
		bridge.pop();
		if (w >= trucks.front()) {
			bridge.push(trucks.front());
			w -= trucks.front();
			trucks.pop();
		}
		else
			bridge.push(0);
		++ans;
	}
	if(bridge.size() > 0)
		ans += bridge.size();
	cout << ans;
}