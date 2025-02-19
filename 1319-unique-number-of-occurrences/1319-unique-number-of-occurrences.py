from collections import  Counter
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count = Counter(arr)
        occurence = list(count.values())
        return len(occurence) == len(set(occurence))

        