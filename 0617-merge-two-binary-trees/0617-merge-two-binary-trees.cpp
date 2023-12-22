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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root2 == nullptr)
            return root1;
        if(root1 == nullptr)
            return root2;
        dfs(root1, nullptr, root2, nullptr);
        return root1;
    }
    void dfs(TreeNode* t1, TreeNode* t1prev, TreeNode* t2, TreeNode* t2prev){
        if(nullptr == t1 && nullptr == t2)
            return;
        if(t1 == nullptr){
            if(t2prev->right == t2)
                t1prev->right = t2;
            else if(t2prev->left == t2)
                t1prev->left = t2;
        }
        else if(t2 == nullptr){
        }
        else{
            dfs(t1->left, t1, t2->left, t2);
            dfs(t1->right, t1, t2->right, t2);
            t1->val += t2->val;
        }
    }
};