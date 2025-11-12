class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 1) {
            vector<int> singleList;
            singleList.push_back(nums[0]);
            res.push_back(singleList);
            return res;
        }

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            vector<int> remainingNums;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    remainingNums.push_back(nums[j]);
                }
            }
            
            vector<vector<int>> perms = permute(remainingNums);
            for (vector<int> p : perms) {
                p.insert(p.begin(), n);
                res.push_back(p);  
            }
        }
        
        return res;    
    }
};