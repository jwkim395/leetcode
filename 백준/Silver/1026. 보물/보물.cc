#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A;
	vector<int> B;
    for(int i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
	sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += A[i]*B[n-i-1];
    }
    cout << ans;
	return 0;
}