/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = new TreeNode;
        dfs(ans, nums, 0, nums.size() - 1);
        return ans;
    }
    void dfs(TreeNode* t, vector<int>& nums, int st, int end){
        if(end < st)
            return;
        int mid = (st + end)/2;
        t->val = nums[mid];
        if(st != mid){
            t->left = new TreeNode;
            dfs(t->left, nums, st, mid - 1);
        }
        if(end != mid){
            t->right = new TreeNode;
            dfs(t->right, nums, mid + 1, end);
        }
    }
};