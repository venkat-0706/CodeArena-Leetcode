class Solution {
public:
    bool isPal(const string &s, int start, int end) {
        if (start >= end){
            return true;
        } 
        return (s[start] == s[end]) && isPal(s, start + 1, end - 1);
    }

    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }  
        string s = to_string(x);
        return isPal(s, 0, s.size() - 1);
    }
};
