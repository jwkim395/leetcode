class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idxG = 0;
        int idxS = 0;
        while(idxS < s.size() && idxG < g.size()){
            if(g[idxG] <= s[idxS]){
                ++idxG;
                ++idxS;
                ++ans;
            }
            else
                ++idxS;
        }
        return ans;
    }
};