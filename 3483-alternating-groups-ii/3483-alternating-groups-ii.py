class Solution:  
    def numberOfAlternatingGroups(self, colors, k):  
        n = len(colors)  
        if n < k:  
            return 0  

        count = 0  
        length = 1  
        prev_color = colors[0]  

        for i in range(1, n):  
            if colors[i] != prev_color:  
                length += 1  
                if length >= k:  
                    count += 1  
            else:  
                length = 1  
            prev_color = colors[i]  

        if k > 1:  
            for i in range(min(k - 1, n)):  
                if colors[i] != prev_color:  
                    length += 1  
                    if length >= k:  
                        count += 1  
                else:  
                    break  
                prev_color = colors[i]  

        return count  