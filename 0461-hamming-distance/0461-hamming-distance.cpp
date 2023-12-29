class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int t = x^y;
        for(int i = 0; i < 32; ++i){
            if((t >> i) & 1)
                ++ans;
        }
        return ans;
    }
};