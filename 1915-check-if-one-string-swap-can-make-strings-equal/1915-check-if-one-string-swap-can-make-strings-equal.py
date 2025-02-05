class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        temp = []
        for a,b in zip(s1,s2):
            if a != b:
                temp.append(a)
                temp.append(b)
        a, b, c, d, e = (temp + [''] * 5)[:5]  
        return not a or (not e and a == d and b == c)

        