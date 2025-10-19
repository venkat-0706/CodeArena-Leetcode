class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        vis = set([s])
        smallest = s
        q = [s]

        while q:
            cur = q.pop(0)
            if cur < smallest:
                smallest = cur

            chars = list(cur)
            for i in range(1, len(chars), 2):
                chars[i] = str((int(chars[i]) + a) % 10)
            added = ''.join(chars)
            if added not in vis:
                vis.add(added)
                q.append(added)

            rotated = cur[-b:] + cur[:-b]
            if rotated not in vis:
                vis.add(rotated)
                q.append(rotated)

        return smallest