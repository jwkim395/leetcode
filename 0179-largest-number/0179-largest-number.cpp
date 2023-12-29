bool cmp(int a, int b){
    string n1 = to_string(a) + to_string(b);
    string n2 = to_string(b) + to_string(a);
    return n1 > n2;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); ++i)
            ans += to_string(nums[i]);
        if(ans[0] == '0')
            return "0";
        return ans;
    }
    
};