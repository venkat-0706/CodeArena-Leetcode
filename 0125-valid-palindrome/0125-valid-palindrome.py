class Solution:
    def isPalindrome(self, s: str) -> bool:
        rev =  ''.join(char.lower() for char in s if char.isalnum())
        if rev == rev[::-1]:
            return True
        else:
            return False