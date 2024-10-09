class Solution:
    def isPalindrome(self, x: int) -> bool:
        n = str(x)
        if n == n[::-1]:
            return True
        else:
            return False
