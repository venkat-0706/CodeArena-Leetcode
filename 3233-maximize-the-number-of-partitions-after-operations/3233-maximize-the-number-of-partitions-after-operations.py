class Solution:
    ALPHABET_SIZE = 26

    def maxPartitionsAfterOperations(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if k == self.ALPHABET_SIZE:
            return 1

        n = len(s)
        ansr = [0] * n
        usedr = [0] * n
        used = 0
        cntUsed = 0
        ans = 1

        for i in range(n - 1, -1, -1):
            ch = ord(s[i]) - ord('a')
            if (used & (1 << ch)) == 0:
                if cntUsed == k:
                    cntUsed = 0
                    used = 0
                    ans += 1
                used |= (1 << ch)
                cntUsed += 1
            ansr[i] = ans
            usedr[i] = used

        ansl = 0
        ans = ansr[0]

        l = 0
        while l < n:
            used = 0
            cntUsed = 0
            usedBeforeLast = 0
            usedTwiceBeforeLast = 0
            last = -1
            r = l

            while r < n:
                ch = ord(s[r]) - ord('a')
                if (used & (1 << ch)) == 0:
                    if cntUsed == k:
                        break
                    usedBeforeLast = used
                    last = r
                    used |= (1 << ch)
                    cntUsed += 1
                elif cntUsed < k:
                    usedTwiceBeforeLast |= (1 << ch)
                r += 1

            if cntUsed == k:
                if last - l > bin(usedBeforeLast).count('1'):
                    ans = max(ans, ansl + 1 + ansr[last])
                if last + 1 < r:
                    if last + 2 >= n:
                        ans = max(ans, ansl + 1 + 1)
                    else:
                        if bin(usedr[last + 2]).count('1') == k:
                            canUse = ((1 << self.ALPHABET_SIZE) - 1) & ~used & ~usedr[last + 2]
                            if canUse > 0:
                                ans = max(ans, ansl + 1 + 1 + ansr[last + 2])
                            else:
                                ans = max(ans, ansl + 1 + ansr[last + 2])
                            l1 = ord(s[last + 1]) - ord('a')
                            if (usedTwiceBeforeLast & (1 << l1)) == 0:
                                ans = max(ans, ansl + 1 + ansr[last + 1])
                        else:
                            ans = max(ans, ansl + 1 + ansr[last + 2])

            l = r
            ansl += 1

        return ans