class Solution:
    def reverse(self, x: int) -> int:
        Max_int = 2 ** 31 - 1
        Min_int = -2 ** 31

        res = 0
        lamp = False
        if x < 0:
            x = x * (-1)
            lamp = True
        while x > 0:
            res = res * 10 + x % 10
            x //= 10
        
        if res > Max_int or res < Min_int:
            return 0
        else:
            if lamp:
                res = -res
            return res