class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        const long long MAX_INT = INT_MAX;
        const long long MIN_INT = INT_MIN;
        int i = 0;
        int n = s.length();
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n) {
            return 0;
        }
        int sign = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            res = res * 10 + digit;
            if (sign * res <= INT_MIN) {
                return INT_MIN;
            }
            if (sign * res >= INT_MAX) {
                return INT_MAX;
            }
            
            i++;
        }
        return static_cast<int>(res * sign);     
    }
};