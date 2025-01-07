
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;

        sort(words.begin(), words.end(), 
             [&](const string &a, const string &b) -> bool {
                 return a.size() > b.size();
             });
        
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i + 1; j < words.size(); ++j) {
                if(words[i].find(words[j]) != string::npos) {
                    result.push_back(words[j]);
                }
            }
        }
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
    }
};