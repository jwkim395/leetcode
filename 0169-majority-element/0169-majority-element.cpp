class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = merge(nums, 0, nums.size() - 1);
        return ans;
    }
    int merge(vector<int>& nums, int st, int end){
        if(end - st == 0)
            return nums[st];
        int mid = (st + end) / 2;
        int leftSide = merge(nums, st, mid);
        int rightSide = merge(nums, mid + 1, end);
        if(count(nums.begin() + st, nums.begin() + mid, leftSide) > count(nums.begin() + mid, nums.begin() + end, rightSide))
            return leftSide;
        return rightSide; 
    }
    int majorityElement222(vector<int>& nums) {
        map<int, int> cnt;
        for(int i = 0; i < nums.size(); ++i){
            ++cnt[nums[i]]; 
            if(cnt[nums[i]] > nums.size() / 2)
                return nums[i];
        }
        return 0;
    }
};