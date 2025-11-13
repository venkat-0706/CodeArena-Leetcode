class Solution {
public:
    int maxOperations(string s) {
        int count = 0;
        int countOne = 0, i = 0;
        while(i<s.size()){
            bool check = false;
            while(i<s.size() && s[i]=='1'){
                countOne++;
                i++;
            }
            while(i<s.size() && s[i]=='0'){
                check = true;
                i++;
            }
            if(check) count+=countOne;
        }
        return count;
    }
};