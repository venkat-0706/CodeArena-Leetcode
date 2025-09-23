class Solution {
public:
    string solve(string s , int n){
        if(n == 1) return s;
        
        int i = 0;
        string ans = "";
        while(i < s.size()){
            int cnt = 1;
            while(i<s.size()-1 && s[i] == s[i+1]){
                cnt++;
                i++;
            }
            ans += to_string(cnt);
            ans += s[i];
            i++;
        }

        return solve(ans , n-1);
    }
    string countAndSay(int n) {

        return solve("1" , n);        
    }
};