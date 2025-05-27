class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start ^ goal;
        int count = 0;
        while(res>0){
            count++;
            res = res&(res-1);
        }
        return count;
    }
};