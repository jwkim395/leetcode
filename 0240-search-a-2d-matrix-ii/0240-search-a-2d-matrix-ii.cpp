class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;
        while(col < matrix[0].size() && row >= 0){
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                --row;
            else
                ++col;
        }
        return false;
    }
};