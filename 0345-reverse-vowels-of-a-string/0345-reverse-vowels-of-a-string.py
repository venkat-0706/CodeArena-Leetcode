class Solution:
    def reverseVowels(self, s: str) -> str:
        word = list(s)
        start = 0
        end = len(s) - 1
        vowel = "aeiouAEIOU"
        while start < end:
            while start < end and vowel.find(word[start]) == -1:
                start += 1
            while start < end and vowel.find(word[end]) == -1:
                end -= 1
            word[start],word[end] = word[end],word[start]
            start += 1
            end -= 1
        return "".join(word)
        