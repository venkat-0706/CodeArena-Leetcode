class Solution {
public:
    bool isPalindrome(int x) {
        long long int rev =0 , n=x;
        if(x<0){
            return false;
        }
        while(x!=0){
            rev *=  10;
            rev += (x%10);
            x  /=  10;
        }
        if(n==rev) return 1;
        else return 0;
    }
};