class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        if(n<=1){
            return 0;
        }
        vector<bool>prime(n,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
            }
        }
        return count;
    }
};