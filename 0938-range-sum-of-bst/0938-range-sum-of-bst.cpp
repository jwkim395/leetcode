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
private:
    int ans;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0;
        dfs(root, low, high);
        return ans;
    }
    void dfs(TreeNode* t, int low, int high){
        if(nullptr == t)
            return;
        if(t->val <= high && t->val >= low)
            ans += t->val;
        dfs(t->left, low, high);
        dfs(t->right, low, high);
    }
};