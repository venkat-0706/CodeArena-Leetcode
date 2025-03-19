class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        for c in ransomNote:
            if magazine.count(c) < ransomNote.count(c):
                return False
        return True


        