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
    int ans;
public:
    TreeNode* bstToGst(TreeNode* root) {
        ans = 0;
        dfs(root);
        return root;
    }
    void dfs(TreeNode* t){
        if(nullptr == t)
            return;
        dfs(t->right);
        int v = t->val;
        t->val += ans;
        ans += v;
        dfs(t->left);
    }
};