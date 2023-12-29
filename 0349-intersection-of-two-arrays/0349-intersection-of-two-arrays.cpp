class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> t;
        set<int> inter;
        vector<int> ans;
        for(int i = 0; i < nums1.size(); ++i)
            t.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); ++i){
            if(t.find(nums2[i]) != t.end())
                inter.insert(nums2[i]);
        }
        set<int>::iterator iter;
        for(iter = inter.begin(); iter != inter.end(); iter++)
            ans.push_back(*iter);
        return ans;
    }
};