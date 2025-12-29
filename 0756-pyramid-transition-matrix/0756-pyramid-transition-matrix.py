class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        allowed_map = defaultdict(list)
        for a in allowed:
            allowed_map[a[:2]].append(a[2])
        memo = {}

        def rec(bottom):
            if len(bottom) == 1:
                return True
            if bottom in memo:
                return memo[bottom]

            possible_tops = []
            for i in range(1, len(bottom)):
                pair = bottom[i-1] + bottom[i]
                if pair in allowed_map:
                    possible_tops.append(allowed_map[pair])
                else:
                    memo[bottom] = False
                    return False
            for next_top_tuple in product(*possible_tops):
                next_top = "".join(next_top_tuple)
                if rec(next_top):
                    memo[bottom] = True
                    return True
            memo[bottom] = False
            return False

        return rec(bottom)