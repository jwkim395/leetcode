class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int st = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(st <= intervals[i][0] && end >= intervals[i][0])
                end = max(intervals[i][1], end);
            else{
                vector<int> temp;
                temp.push_back(st);
                temp.push_back(end);
                ans.push_back(temp);
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> temp;
        temp.push_back(st);
        temp.push_back(end);
        ans.push_back(temp);

        return ans;
    }
};