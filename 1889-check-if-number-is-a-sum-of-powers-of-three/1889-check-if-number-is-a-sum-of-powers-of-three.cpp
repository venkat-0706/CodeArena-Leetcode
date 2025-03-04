class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i=15 ; i >= 0; i--){
            int x = pow(3,i);
            if(x <= n){
                n -= x;
            }
            if(n == 0) {
                return 1;
            }
        }
        return 0;
        
    }
};