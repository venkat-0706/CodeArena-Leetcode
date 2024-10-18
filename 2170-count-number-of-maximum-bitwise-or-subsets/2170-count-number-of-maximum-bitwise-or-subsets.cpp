class Solution {
public:
    int n;
    unsigned max_OR;
    int f(int i, unsigned acc_or, vector<int>& nums){
        if (i<0) return (acc_or==max_OR)?1:0;
        int skip=f(i-1, acc_or, nums);
        int take=f(i-1, acc_or| nums[i], nums);
        return skip+take;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        max_OR=accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        return f(n-1, 0, nums);
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();