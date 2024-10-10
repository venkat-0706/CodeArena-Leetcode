class Solution {
    public boolean canJump(int[] nums) {
        int targetNumIndex = nums.length - 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (targetNumIndex <= i + nums[i]) {
                targetNumIndex = i;
            }
        }
        return targetNumIndex == 0;
    }
}