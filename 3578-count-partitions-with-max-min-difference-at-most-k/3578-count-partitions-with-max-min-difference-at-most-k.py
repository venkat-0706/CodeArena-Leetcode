class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:

        left, cnt, mod_ = 0, 1, 1_000_000_007
        mnQueue, mxQueue, dp = deque(), deque(), [cnt]
        
        for rght, num in enumerate(nums):
            while mxQueue and num > nums[mxQueue[-1]]:
                mxQueue.pop()
            while mnQueue and num < nums[mnQueue[-1]]:
                mnQueue.pop()

            mxQueue.append(rght)    
            mnQueue.append(rght)

            while nums[mxQueue[0]] - nums[mnQueue[0]] > k:
                cnt-= dp[left]
                left+= 1
                
                if left > mnQueue[0]: mnQueue.popleft()
                if left > mxQueue[0]: mxQueue.popleft()

            dp.append(cnt)
            cnt*= 2
            cnt%= mod_

        return dp[-1] %mod_