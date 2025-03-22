class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> temp = new HashSet<>();
        for(int num : nums){
            if(!temp.add(num)){
                return true;
            }
        }
        return false;
    }
}