from collections import Counter
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        rep = Counter(arr)
        freq = list(rep.values())
        return len(freq) == len(set(freq))
        