class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        count = 0
        while num1!=0 and num2!=0:
            if num1 >= num2:
                num1 = num1-num2
            elif num2>=num1:
                num2= num2-num1
            count += 1
        return count
        