class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size();
        int left= 0;
        for (; left+1 < n && arr[left] <= arr[left+1]; left++); 
        if (left== n-1) return 0;
        int right = n-1;
        for (; right>left && arr[right-1] <= arr[right]; right--);
        int remove = min(n-left-1, right);
        for (int i = 0, j = right; i <= left && j < n; ) {
            if (arr[i] <= arr[j]) {
                remove = min(remove, j-i-1);
                i++;
            } 
            else j++;  
        }
        
        return remove;
    }
};