class Solution(object):
    def longestBalanced(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        tree_min = [0] * (4 * n)
        tree_max = [0] * (4 * n)
        lazy = [0] * (4 * n)
        
        def push(v):
            if lazy[v] != 0:
                lazy[2*v] += lazy[v]
                tree_min[2*v] += lazy[v]
                tree_max[2*v] += lazy[v]
                lazy[2*v+1] += lazy[v]
                tree_min[2*v+1] += lazy[v]
                tree_max[2*v+1] += lazy[v]
                lazy[v] = 0
                
        def update(v, tl, tr, l, r, add):
            if l > r:
                return
            if l == tl and r == tr:
                tree_min[v] += add
                tree_max[v] += add
                lazy[v] += add
            else:
                push(v)
                tm = (tl + tr) // 2
                update(2*v, tl, tm, l, min(r, tm), add)
                update(2*v+1, tm+1, tr, max(l, tm+1), r, add)
                tree_min[v] = min(tree_min[2*v], tree_min[2*v+1])
                tree_max[v] = max(tree_max[2*v], tree_max[2*v+1])
                
        def find_first_zero(v, tl, tr, limit):
            if tl > limit:
                return -1
            if tree_min[v] > 0 or tree_max[v] < 0:
                return -1
            if tl == tr:
                return tl if tree_min[v] == 0 else -1
            push(v)
            tm = (tl + tr) // 2
            res = find_first_zero(2*v, tl, tm, limit)
            if res != -1:
                return res
            return find_first_zero(2*v+1, tm+1, tr, limit)

        last_pos = {}
        max_len = 0
        
        for i, x in enumerate(nums):
            val = 1 if x % 2 == 0 else -1
            prev = last_pos.get(x, -1)
            last_pos[x] = i
            update(1, 0, n-1, prev + 1, i, val)
            left_idx = find_first_zero(1, 0, n-1, i)
            if left_idx != -1:
                max_len = max(max_len, i - left_idx + 1)
                
        return max_len