class Solution:
    def mono(self, s: str) -> int:
        if not s:
            return 0
        cnt = 1
        ans = 1
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cnt += 1
            else:
                cnt = 1
            ans = max(ans, cnt)
        return ans

    def duo(self, s: str, c1: str, c2: str) -> int:
        pos: Dict[int, int] = {0: -1}
        ans = 0
        delta = 0
        for i, ch in enumerate(s):
            if ch != c1 and ch != c2:
                pos.clear()
                pos[0] = i
                delta = 0
                continue

            if ch == c1:
                delta += 1
            else:
                delta -= 1

            if delta in pos:
                ans = max(ans, i - pos[delta])
            else:
                pos[delta] = i

        return ans

    def trio(self, s: str) -> int:
        cnt0 = cnt1 = cnt2 = 0  
        pos: Dict[Tuple[int, int], int] = {(0, 0): -1}
        ans = 0
        for i, ch in enumerate(s):
            if ch == 'a':
                cnt0 += 1
            elif ch == 'b':
                cnt1 += 1
            else:  
                cnt2 += 1

            key = (cnt1 - cnt0, cnt2 - cnt0)

            if key in pos:
                ans = max(ans, i - pos[key])
            else:
                pos[key] = i

        return ans

    def longestBalanced(self, s: str) -> int:
        return max(
            self.mono(s),
            self.duo(s, 'a', 'b'),
            self.duo(s, 'a', 'c'),
            self.duo(s, 'b', 'c'),
            self.trio(s),
        )