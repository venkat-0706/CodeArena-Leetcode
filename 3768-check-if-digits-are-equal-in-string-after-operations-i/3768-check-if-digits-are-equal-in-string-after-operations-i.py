class Solution(object):
    def hasSameDigits(self, s):
        i = 0
        res = ""
        while len(s) > 2 and i < len(s) - 1:
            res += str((int(s[i]) + int(s[i + 1])) % 10)
            i += 1
            if i == len(s) - 1:
                s = res
                i = 0
                res = ""
        return len(s) == 2 and s[0] == s[1]