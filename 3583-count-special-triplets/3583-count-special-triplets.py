class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        MOD=10**9+7
        ans,n=0,len(nums)
        pref=Counter()
        suff=Counter(nums)
        for i in range(n):
            suff[nums[i]]-=1
            ans=(ans+pref[nums[i]*2]*suff[nums[i]*2])%MOD
            pref[nums[i]]+=1
        return ans