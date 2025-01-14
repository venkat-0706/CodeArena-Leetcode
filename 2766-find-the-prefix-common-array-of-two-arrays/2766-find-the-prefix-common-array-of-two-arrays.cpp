class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, pair<bool, bool>> M;
        vector<int> ANS(A.size());
        int c = 0;
        for (int i = 0; i < A.size(); i++) {
            if (M.find(A[i]) == M.end()) {
                M[A[i]].first = true;
            } else {
                if (!M[A[i]].first && M[A[i]].second) {
                    c++;
                    M[A[i]].first = true;
                }
            }
            if (M.find(B[i]) == M.end()) {
                M[B[i]].second = true;
            } else {
                if (!M[B[i]].second && M[B[i]].first) {
                    c++;
                    M[B[i]].second = true;
                }
            }
            ANS[i] = c;
        }
        return ANS;
    }
};