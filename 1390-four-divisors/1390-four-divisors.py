from typing import List

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        total = 0

        for n in nums:
            temp = n
            factors = {}

            # Prime factorization
            d = 2
            while d * d <= temp:
                while temp % d == 0:
                    factors[d] = factors.get(d, 0) + 1
                    temp //= d
                d += 1

            if temp > 1:
                factors[temp] = factors.get(temp, 0) + 1

            # Case 1: n = p^3
            if len(factors) == 1:
                p, exp = list(factors.items())[0]
                if exp == 3:
                    total += 1 + p + p*p + p*p*p

            # Case 2: n = p * q
            elif len(factors) == 2:
                items = list(factors.items())
                if items[0][1] == 1 and items[1][1] == 1:
                    p = items[0][0]
                    q = items[1][0]
                    total += 1 + p + q + p*q

        return total
