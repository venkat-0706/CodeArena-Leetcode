class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        lis = set()
        for num in arr:
            if  num *2 in lis or (num%2==0 and num//2 in lis):
                return True
            lis.add(num)
        return False