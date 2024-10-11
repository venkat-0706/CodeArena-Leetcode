
class Solution {
public:
    set<string> dict;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict)dict.insert(x);
        vector<string> res;
        rec(s, 0, "", res);
        return res;
    }

    void rec(string s, int beg, string curr, vector<string>& res) {
        if(beg==s.size()) {
            if(curr[0]==' ')curr = curr.substr(1);
            res.push_back(curr);
        }
        string temp = "";
        for(int i=beg;i<s.size();i++) {
            temp.push_back(s[i]);
            if(dict.count(temp)) {
                rec(s, i+1, curr + " " + temp, res);
            }
        }
    }
};