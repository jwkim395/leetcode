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
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode* t, int d){
        if(t == nullptr)
            return 0;
        int l = dfs(t->left, ans);
        int r = dfs(t->right, ans);
        ans = max(ans, l+r);
        return max(l, r) + 1;
    }
};