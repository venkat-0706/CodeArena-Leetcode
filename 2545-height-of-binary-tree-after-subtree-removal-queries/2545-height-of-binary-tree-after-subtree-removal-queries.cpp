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
    unordered_map<int, int> mp1, mp2, sz;
    int id = 0;
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        vector<int> ans;
        dfs(root, 0);
        
        vector<int> left(id), right(id);
        for(int i = 0; i < left.size(); i++) {
            left[i] = mp2[i];
            if(i) left[i] = max(left[i - 1], left[i]);
        }
        
        for(int i = right.size() - 1; i >= 0; i--) {
            right[i] = mp2[i];
            if(i + 1 < right.size()) right[i] = max(right[i], right[i + 1]);
        }
        
        for(int i = 0; i < q.size(); i++) {
            int nodeid = mp1[q[i]];
            int l = nodeid, r = l + sz[nodeid] - 1;
            int h = 0;
            if(l > 0) h = max(h, left[l - 1]);
            if(r + 1 < right.size()) h = max(h, right[r + 1]);
            ans.push_back(h);
        }
        return ans;
    }
    
    int dfs(TreeNode* root, int h) { //return the size of the subtree
        if(root == NULL) {
            return 0;
        }
        mp1[root -> val] = id;
        mp2[id] = h;
        id++;
        int lz = dfs(root -> left, h + 1);
        int rz = dfs(root -> right, h + 1);
        sz[mp1[root -> val]] = (1 + lz + rz);
        return 1 + lz + rz;
    }
};