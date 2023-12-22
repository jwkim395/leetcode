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
    vector<int> v;
public:
    int minDiffInBST(TreeNode* root) {
        int ans = 100001;
        dfs(root);
        for(int i = 0; i < v.size()-1; ++i)
            ans = min(ans, v[i+1] - v[i]);
        return ans;
    }
    void dfs(TreeNode* t){
        if(t == nullptr)
            return;
        dfs(t->left);
        v.push_back(t->val);
        dfs(t->right);
    }
};