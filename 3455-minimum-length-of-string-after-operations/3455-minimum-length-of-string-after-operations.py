class Solution:
    def minimumLength(self, s: str) -> int:
        freq_map = {}
        
        for c in s:
            freq_map[c] = freq_map.get(c, 0) + 1
        
        deletions = 0

        for count in freq_map.values():
            if count > 2:
                if count % 2 == 0:
                    deletions += (count - 2)
                else:
                    deletions += (count - 1)
        
        return len(s) - deletions