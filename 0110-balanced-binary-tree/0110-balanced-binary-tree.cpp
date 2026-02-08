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
    using int2=pair<int, bool>;
    int2 dfs(TreeNode* root){
        if (!root) return {0, 1};
        auto [lH, lB]=dfs(root->left);
        auto [rH, rB]=dfs(root->right);
        return {1+max(lH, rH), lB & rB & abs(lH-rH)<=1};
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
};