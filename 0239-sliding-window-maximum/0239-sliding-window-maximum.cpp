class Solution {
public:
    vector<int> ans;
    deque<int> win;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); ++i){
            while(win.size() > 0 && win.front() < i - k + 1)
                win.pop_front();
            while(win.size() > 0 && nums[i] > nums[win.back()])
                win.pop_back();
            win.push_back(i);
            if(i >= k - 1)
                ans.push_back(nums[win.front()]);
        }
        return ans;
    }
    
};