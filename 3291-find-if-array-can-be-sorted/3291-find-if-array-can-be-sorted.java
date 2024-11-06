class Solution {
    public boolean canSortArray(int[] nums) {
        int[]ans=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            ans[i]=nums[i];
        }
        Arrays.sort(ans);
        if(Arrays.equals(ans,nums))return true;
        for(int i=0;i<nums.length-1;i++){
            for(int j=0;j<nums.length-1-i;j++){
                if(Integer.bitCount(nums[j])==Integer.bitCount(nums[j+1])&&nums[j]>nums[j+1]){
                    int t=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=t;
                } 
                  
            }
        }
        return Arrays.equals(nums,ans);
    
    }
}