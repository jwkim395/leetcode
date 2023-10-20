#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            for(int j = i+1; j < nums.size(); ++j)
                if (target == nums[i] + nums[j]) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> v = { 3,3 };
    vector<int>answer = s.twoSum(v, 6);
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << endl;
    return 0;
}