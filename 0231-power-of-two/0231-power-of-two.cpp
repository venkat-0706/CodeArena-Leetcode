class Solution {
public:
    bool isPowerOfTwo(long n) {
     if(n==0){
        return false;
     }   
     while(n!=1){
        if(n&1!=0){
            return false;
        }
        n=n/2;
     }
     return true;
    }
};