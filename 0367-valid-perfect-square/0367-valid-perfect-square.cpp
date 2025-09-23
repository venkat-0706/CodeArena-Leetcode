class Solution {
public:
    bool isPerfectSquare(int num) {
        int low= 0 ;
        int high = num;
        while(low <= high){
            long long mid = (low+high)/2;
            long long res = mid*mid;
            if(res == num){
                return true;
            } else if (res < num){
                low = mid+1;
            } else{
                high = mid-1;
            }
            
        }
        return false;
    }
};