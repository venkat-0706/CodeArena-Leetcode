class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zero;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero.push_back(i);
        }
        int ones = n - zero.size(); 
        zero.push_back(n); 

        int res = 0, sid = 0; 

        for (int left = 0; left < n; left++) {
           
            for (int id = sid; id < zero.size() - 1; id++) {
                int cnt0 = id - sid + 1; 
                if (cnt0 * cnt0 > ones) break;
                int p = zero[id], q = zero[id + 1];
                int cnt1 = zero[id] - left - (id - sid);
                if (cnt1 >= cnt0 * cnt0) {
                    res += q - p;
                } else {
                    res += max(q - p - (cnt0 * cnt0 - cnt1), 0);
                }
            }
            if (s[left] == '0') {
                sid++;
            } else {
               
                res += zero[sid] - left;
                ones--;
            }
        }
        return res;
    }
};