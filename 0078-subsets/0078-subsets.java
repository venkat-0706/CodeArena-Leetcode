class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> sets = new ArrayList<>();
        int n = nums.length;
        int subsetsCount = 1 << n; // 2^n subsets

        for (int i = 0; i < subsetsCount; ++i) {
            List<Integer> subset = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    subset.add(nums[j]);
                }
            }
            sets.add(subset);
        }
        return sets;
    }


}