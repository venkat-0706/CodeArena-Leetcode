class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, sTmpIdx = -1, starIdx = -1;
        int m = s.size(), n = p.size();

        while (i < m) {
            if (j < n && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
                starIdx = j;
                sTmpIdx = i;
                j++;
            } else if (starIdx != -1) {
                j = starIdx + 1;
                sTmpIdx++;
                i = sTmpIdx;
            } else {
                return false;
            }
        }

        while (j < n && p[j] == '*') j++;

        return j == n;
    }
};