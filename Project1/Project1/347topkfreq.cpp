bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            if (count.find(nums[i]) == count.end())
                count[nums[i]] = 1;
            else
                ++count[nums[i]];
        }
        vector<pair<int, int>> sortCount(count.begin(), count.end());
        sort(sortCount.begin(), sortCount.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(sortCount[i].first);
        }
        return ans;
    }

};