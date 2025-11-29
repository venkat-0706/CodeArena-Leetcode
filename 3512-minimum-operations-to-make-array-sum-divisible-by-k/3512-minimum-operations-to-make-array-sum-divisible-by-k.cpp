class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto x : nums) sum += x;
        return sum % k;
    }
};