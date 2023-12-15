class Solution {
public:
    vector<vector<int>> ans;
public:
    int sum(vector<int>& nums) {
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            answer += nums[i];
        }
        return answer;
    }
    void dfs(vector<int>& nums, vector<int>& temp, int st, int target) {
        if (target == sum(temp)) {
            ans.push_back(temp);
            return;
        }
        if (target < sum(temp)) {
            return;
        }
        for (int i = st; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            dfs(nums, temp, i, target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> t;
        dfs(candidates, t, 0, target);
        return ans;
    }

};