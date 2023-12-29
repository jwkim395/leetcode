class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;// 0
        int white = 0; // 1
        int blue = nums.size(); // 2
        
        while(blue > white){
            if(nums[white] < 1){// 0
                int temp = nums[red];
                nums[red] = nums[white];
                nums[white] = temp;
                ++white;
                ++red;
            }
            else if(nums[white] > 1){ // 2
                --blue;
                int temp = nums[blue];
                nums[blue] = nums[white];
                nums[white] = temp;
            }
            else
                ++white;
        }
    }
};