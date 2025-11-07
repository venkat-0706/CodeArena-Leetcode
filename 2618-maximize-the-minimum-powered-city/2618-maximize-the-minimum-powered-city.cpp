using ll = long long;
class Solution {
public:
long long maxPower(vector<int>& stations, int r, int k) {
    
    int n = stations.size();
    vector<ll>a(n+1);
    for(int i=0;i<n;i++){
        int l = max(i-r,0);
        int x = min(i+r,n-1);
        a[l]+=1ll*stations[i];
        a[x+1]-=1ll*stations[i];
        
    }
    
    
    for(int i=1;i<n;i++) a[i]+=a[i-1];
    
    long long hi = LLONG_MAX, lo = 0;
    long long ans = 0;
    
    while(lo<=hi){
        long long mid = lo+(hi-lo)/2; // this technique avoids overflow.
        
        vector<long long> add(n+1); // the array to maintain all updates.
        
        long long rem = k; // number of stations we can place.
        for(int i=0;i<n;i++){
            
            if(i)add[i]+=add[i-1];
            ll got = a[i]+add[i];
            
            if(got<mid){
                long long need = mid-got;
                rem-=need;
                if(rem<0) break;
                int j = min(i+r+r,n-1);
                add[i]+=need;
                add[j+1]-=need;
            }
        }
        if(rem>=0){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid - 1;
        }
    }
    return ans;
}
};