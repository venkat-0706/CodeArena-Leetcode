class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned_s = ''.join(char.lower() for char in s if char.isalnum())
        if cleaned_s == cleaned_s[::-1]:
            return True
        else:
            return False      