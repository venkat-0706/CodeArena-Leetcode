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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        int n=1;
        vector<TreeNode*> a1;
        unordered_map<TreeNode*, TreeNode*> par;
        unordered_map<TreeNode*,int> childSum;
        a1.push_back(root);
        root->val = 0;
        
        while(n){
            int sum=0,sChild=0;
            vector<TreeNode*> a2;
            
            for(int i=0;i<n;i++){
                sChild=0;
                auto fr = a1[i];
                sum += fr->val;
                if(fr->left){
                    a2.push_back(fr->left);
                    sChild+=fr->left->val;
                    par[fr->left] = fr;
                }
                if(fr->right){
                    a2.push_back(fr->right);
                    sChild += fr->right->val;
                    par[fr->right] = fr;
                }
                childSum[fr] = sChild;
            }
            for(int i=0;i<n;i++){
                auto fr = a1[i];
                fr->val = sum - childSum[par[fr]];
            }
            a1=a2;
            n=a1.size();
        }
        return root;
    }
};