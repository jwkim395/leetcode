#include <iostream>
#include <string>

using namespace std;

int main() {
	int p;
	string seats;
	cin >> p;
	cin >> seats;
	int ans = 0;

	for (int i = 0; i < seats.length(); ++i) {
		ans += 1;
		if (seats[i] == 'L')
			++i;
	}
	ans += 1;
	if (ans >= p)
		cout << p;
	else
		cout << ans;
}