class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        n = len(arr)
        low , high =  0 , n-1
        while low < high :
            mid = (low + high) // 2
            if arr[mid] < arr[mid+1]:
                low = mid+1
            else:
                high = mid

        return low
        