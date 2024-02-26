#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, l, d;
	cin >> n >> l >> d;

	int ans = 0;
	int songIdx = 0;
	int playtime = 0;
	bool breakTime = false;
	while (true) {
		if (breakTime) {
			if (ans % d == 0)
				break;
			++playtime;
			++ans;
			if (playtime % 5 == 0) {
				breakTime = !breakTime;
				playtime = 0;
			}
		}
		else if(songIdx == n){
			if(ans % d != 0)
				ans += (d - (ans % d));
			break;
		}
		else {
			++ans;
			++playtime;
			if (playtime % l == 0) {
				++songIdx;
				playtime = 0;
				breakTime = !breakTime;
			}
		}
	}
	cout << ans;

	return 0;
}