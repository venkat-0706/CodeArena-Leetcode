class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        mini = min(len(word1), len(word2))
        merge = [word1[i] + word2[i] for i in range (mini) ]
        merge.append(word1[mini:])
        merge.append(word2[mini:])
        return ''.join(merge)
        