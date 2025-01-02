class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v;
        string temp = "aeiou";
        set<char> s;
        for (auto i : temp)
            s.insert(i);

        int prefix = 0;
        for (auto i : words) {
            char c1 = i[0];
            char c2 = i[i.size() - 1];
            if (s.find(c1) != s.end() && s.find(c2) != s.end()) {
                prefix += 1;
                v.push_back(prefix);
            } else {
                v.push_back(prefix);
            }
        }
        vector<int> ans;
        for (auto i : queries) {
            int l = i[0];
            int r = i[1];
            if(l == 0)
            ans.push_back(v[r]);
            else
            ans.push_back(abs(v[r] - v[l - 1]));
        }
        return ans;
    }
};