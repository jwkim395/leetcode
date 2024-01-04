class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gSum = 0;
        int cSum = 0;
        int ans = 0;
        int tank = 0;
        for(int i = 0; i < gas.size(); ++i){
            gSum += gas[i];
            cSum += cost[i];
            if(tank + gas[i] < cost[i]){
                ans = i + 1;
                tank = 0;
            }
            else
                tank += gas[i] - cost[i];
        }
        if(gSum < cSum)
            return -1;
        return ans;
    }
};