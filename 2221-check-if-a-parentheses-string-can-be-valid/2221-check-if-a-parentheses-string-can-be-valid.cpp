class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;
        int openCount = 0; 
        int flexibleCount = 0; 
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                flexibleCount++;
            } else if (s[i] == '(') {
                openCount++;
            } else { // s[i] == ')'
                if (openCount > 0) {
                    openCount--;
                } else if (flexibleCount > 0) {
                    flexibleCount--;
                } else {
                    return false;
                }
            }
        }
        int closeCount = 0;
        flexibleCount = 0; 
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                flexibleCount++;
            } else if (s[i] == ')') {
                closeCount++;
            } else {
                if (closeCount > 0) {
                    closeCount--;
                } else if (flexibleCount > 0) {
                    flexibleCount--;
                } else {
                    return false; 
                }
            }
        }
        return true;
    }
};