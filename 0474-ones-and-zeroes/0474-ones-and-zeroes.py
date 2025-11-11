class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = {(0, 0): 0}

        for s in strs:
            ones = s.count('1')
            zeroes = s.count('0')
            newdp = {}

            for (prevZeroes, prevOnes), val in dp.items():
                newZeroes, newOnes = prevZeroes + zeroes, prevOnes + ones
                if newZeroes <= m and newOnes <= n:
                    if (newZeroes, newOnes) not in dp or dp[(newZeroes, newOnes)] < val + 1:
                        newdp[(newZeroes, newOnes)] = val + 1

            dp.update(newdp)

        return max(dp.values())