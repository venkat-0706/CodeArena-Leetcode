class Solution:  
    def clearDigits(self, s: str) -> str:  
        res = 0  
        s = list(s)  
        for i in range(len(s)):  
            if s[i].isdigit():  
                res = max(res - 1, 0)  
            else:  
                s[res] = s[i]  
                res += 1  
        s = s[:res]  
        return "".join(s)  

