class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0){
            if((n&1)!=0){
                count++;
            }
            n=n/2;
        }
        return count;
    }
};