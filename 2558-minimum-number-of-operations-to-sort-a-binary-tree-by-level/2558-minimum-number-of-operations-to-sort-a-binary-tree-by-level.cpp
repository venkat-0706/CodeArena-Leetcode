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
    int minSwaps(vector<int> arr) {
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) mp[copy[i]] = i; 
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (mp[arr[i]] != i) {
                swap(arr[i], arr[mp[arr[i]]]);
                count++;
            }
        }
        return count;
    }

    vector<int> getArray(vector<TreeNode*> arr) {
        vector<int> res;
        for (int i = 0; i < arr.size(); i++) {
            res.push_back(arr[i] -> val);
        }
        return res;
    }
    int minimumOperations(TreeNode* root) {
        vector<TreeNode*> currentLevel, nextLevel;
        nextLevel.push_back(root);
        int count = 0;
        while (nextLevel.size() > 0) {
            swap(currentLevel, nextLevel);
            nextLevel.clear();

            count += minSwaps(getArray(currentLevel));
            for (int i = 0; i < currentLevel.size(); i++) {
                if (currentLevel[i]->left) nextLevel.push_back(currentLevel[i]->left);
                if (currentLevel[i]->right) nextLevel.push_back(currentLevel[i]->right);
            }
        }
        return count;
    }
};