class Solution {
public:
    string compressedString(string word) {
       int n = word.size();
       int ans = 1;
       string rans = "";
       for(int i=1;i<n;i++){
            if(word[i-1] == word[i] && ans < 9){
                ans++;
            }
            else if(word[i-1] == word[i] && ans == 9){
                //rans = rans+to_string(ans)+word[i-1];
                rans.push_back((ans)+'0');
                rans.push_back(word[i-1]);
                ans = 1;
            }
            else{
                rans.push_back((ans)+'0');
                rans.push_back(word[i-1]);
                ans = 1;
            }
       }
       rans.push_back((ans)+'0');
       rans.push_back(word[n-1]);
       return word = rans;
    }
};