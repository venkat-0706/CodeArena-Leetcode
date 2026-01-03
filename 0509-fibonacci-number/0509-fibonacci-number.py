class Solution:
    def fib(self, n: int , memo={}) -> int:
        if n in memo:
            return memo[n]
        if n <= 1:
            return n
        memo[n] = self.fib(n-1,memo)+self.fib(n-2,memo)
        return memo[n]