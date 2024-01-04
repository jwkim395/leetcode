class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = {nums[0]};
        int maxi = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dp.push_back(max(nums[i], dp[i-1] + nums[i]));
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};