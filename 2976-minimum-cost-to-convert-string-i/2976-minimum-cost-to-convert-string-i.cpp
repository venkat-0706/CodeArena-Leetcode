// Use Floyd Warshall's algorithm
int D[26][26];// global variables
class Solution {
public:
    static inline void FW(vector<char>& original, vector<char>& changed, vector<int>& cost){
        fill(&D[0][0], &D[0][0]+26*26, INT_MAX);
        const int sz=original.size();
        for (int i=0; i<sz; i++){
            int row=original[i]-'a';
            int col=changed[i]-'a';
            D[row][col]=min(D[row][col], cost[i]);
        }
        for (int i=0; i<26; i++) D[i][i]=0;

        for(int k=0; k<26; k++)
            for(int i=0; i<26; i++)
                for(int j=0; j<26; j++)
                    D[i][j]=min((long long)D[i][j], (long long)D[i][k]+D[k][j]);

    }

    static long long minimumCost(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        FW(original, changed, cost);
        const int n=source.size();
        long long ans=0;
        for(int i=0; i<n; i++){
            int row=source[i]-'a';
            int col=target[i]-'a';
            if (D[row][col]==INT_MAX) return -1;
            ans+=D[row][col];
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}(); 