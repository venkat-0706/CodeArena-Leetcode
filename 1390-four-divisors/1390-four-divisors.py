from typing import List
from math import isqrt

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        def is_prime(x: int) -> bool:
            if x < 2:
                return False
            for i in range(2, isqrt(x) + 1):
                if x % i == 0:
                    return False
            return True

        total = 0

        for n in nums:
            d = -1
            for i in range(2, isqrt(n) + 1):
                if n % i == 0:
                    d = i
                    break

            if d == -1:
                continue  # prime → only 2 divisors

            m = n // d

            # Case 1: n = p^3 → m = p^2 and d = p
            if m % d == 0 and m // d == d and is_prime(d):
                total += 1 + d + d*d + d*d*d

            # Case 2: n = p * q → p != q and both prime
            elif d != m and is_prime(d) and is_prime(m):
                total += 1 + d + m + n

        return total
