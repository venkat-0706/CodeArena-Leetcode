class Solution:
    def findSmallestInteger(self, nums, value):
        rests = [0] * value

        for num in nums:
            if num >= 0 or num % value == 0:
                rests[num % value] += 1
            else:
                rests[value - (abs(num) % value)] += 1

        mini = float('inf')
        for i in range(value):
            mini = min(mini, rests[i] * value + i)

        return mini


