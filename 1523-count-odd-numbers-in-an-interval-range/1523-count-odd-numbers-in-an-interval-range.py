class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high-low+1+low%2)//2