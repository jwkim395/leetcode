class Solution {
public:
    int fib(int n) {
        vector<int> dp = {0, 1};
        for(int i = 2; i <= n; ++i)
            dp.push_back(dp[i-2] + dp[i-1]);
        return dp[n];
    }
};