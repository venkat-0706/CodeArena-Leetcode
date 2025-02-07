class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        clerd = {}
        freq = {} 
        ans = []
        for ball , clr in queries:
            if ball in clerd:
                old_color = clerd[ball]
                freq[old_color] -= 1
                if freq[old_color] == 0:
                    del freq[old_color]

            clerd[ball] = clr
            freq[clr] = freq.get(clr , 0) + 1
            ans.append(len(freq))

        return ans