class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        drink =  0
        empty = 0
        while numBottles > 0:
            while numBottles > 0  and empty < numExchange:
                drink += 1
                empty += 1
                numBottles -= 1
            if empty == numExchange:
                numExchange += 1
                empty = 0
                numBottles += 1
        return drink
        