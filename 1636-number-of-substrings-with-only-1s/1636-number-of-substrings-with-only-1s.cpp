class Solution {
public:
    int numSub(string s) {
        int ans=0;
        int cnt=0;
        char ch=s[0];
        int mod=1e9+7;
        for(int i=0;i<s.size();i++){
            if(cnt==0&&s[i]=='1'){
                cnt++;
            }
            else if(s[i]=='1'){
                cnt++;
            }
            else{
                long long val=(1LL*cnt*(cnt+1))/2;
                cnt=0;
                ans+=(val%mod);
            }
        }
        long long val=(cnt*(cnt+1))/2;
        ans+=(val%mod);
        return ans;
    }
};