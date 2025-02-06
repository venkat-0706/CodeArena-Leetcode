class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        product_counts = Counter(a * b for a, b in combinations(nums, 2))
        return 8 * sum(comb(C, 2) for C in product_counts.values())