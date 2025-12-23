
class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        proc = []
        ans = m = 0 
        for s,e,v in events:
            proc.append( (s, True, v) )
            proc.append( (e+1, False, v) ) 
        proc.sort()  
        
        for time, is_start, val in proc:
            if is_start:
                ans = max(ans, m+val)
            else:
                m = max(m, val)
        return ans