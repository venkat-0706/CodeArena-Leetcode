class Solution {
public:
    static int countCollisions(string& D) {
        int n=D.size();
        if (n==1) return 0;
        int l=0, r=n-1;
        while (D[l]=='L') l++;
        while (l<r && D[r]=='R') r--;
        if (l>=r) return 0;
        int col=0;
        for( ; l<=r; l++){
           col+=D[l]!='S';
        }
        return col;      
    }
};