class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        for (int i = 0; i < box.size(); ++i) {
            int next = m - 1;
            for (int j = m - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    next = j - 1;
                } else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][next]);
                    next--;
                }
            }   
        }
        vector<vector<char>> newMatrix(m, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                newMatrix[j][n - i - 1] = box[i][j];
            }
        }
        return newMatrix;
    }
};