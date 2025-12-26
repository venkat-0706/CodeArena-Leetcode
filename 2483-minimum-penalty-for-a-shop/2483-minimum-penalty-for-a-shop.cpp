class Solution {
public:
    int bestClosingTime(string& customers) {
        int n = customers.size();
    
        int penalty=0;
        int minP=penalty, minI=0;
    
        for (int i=1; i<=n; i++) {
            int y=customers[i-1]=='Y'?1:-1;
            penalty-=y;
            if (minP>penalty) {
                minP=penalty;
                minI=i;
            }
        }
        return minI;
    }
};