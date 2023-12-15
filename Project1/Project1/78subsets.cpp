class Solution {
public:
    vector<vector<int>> ans;
public:
    void dfs(vector<int>& nums, vector<int>& temp, int st) {
        if (nums.size() == temp.size()) {
            return;
        }
        for (int i = st; i < nums.size(); ++i) {
            if (find(temp.begin(), temp.end(), nums[i]) == temp.end()) {
                temp.push_back(nums[i]);
                ans.push_back(temp);
                dfs(nums, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        ans.push_back(t);
        dfs(nums, t, 0);
        return ans;
    }
};