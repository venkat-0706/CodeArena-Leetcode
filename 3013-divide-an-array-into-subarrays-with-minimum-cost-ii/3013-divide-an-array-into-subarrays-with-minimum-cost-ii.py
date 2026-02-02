class Solution:
    class SmartWindow:
        def __init__(self, k: int):
            self.K = k
            self.low = []   # sorted list
            self.high = []  # sorted list
            self.sumLow = 0

        def windowSize(self) -> int:
            return len(self.low) + len(self.high)

        def _erase_one(self, arr: List[int], x: int) -> bool:
            i = bisect_left(arr, x)
            if i < len(arr) and arr[i] == x:
                arr.pop(i)
                return True
            return False

        def rebalance(self) -> None:
            need = min(self.K, self.windowSize())

            while len(self.low) > need:
                x = self.low.pop()  # largest in low
                self.sumLow -= x
                insort(self.high, x)

            while len(self.low) < need and self.high:
                x = self.high.pop(0)  # smallest in high
                insort(self.low, x)
                self.sumLow += x

        def add(self, x: int) -> None:
            if not self.low or x <= self.low[-1]:
                insort(self.low, x)
                self.sumLow += x
            else:
                insort(self.high, x)
            self.rebalance()

        def remove(self, x: int) -> None:
            if self._erase_one(self.low, x):
                self.sumLow -= x
            else:
                self._erase_one(self.high, x)
            self.rebalance()

        def query(self) -> int:
            return self.sumLow

    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        n = len(nums)
        k -= 1
        window = self.SmartWindow(k)

        for i in range(1, 1 + dist + 1):
            window.add(nums[i])

        ans = window.query()

        for i in range(2, n - dist):
            window.remove(nums[i - 1])
            window.add(nums[i + dist])
            ans = min(ans, window.query())

        return ans + nums[0]