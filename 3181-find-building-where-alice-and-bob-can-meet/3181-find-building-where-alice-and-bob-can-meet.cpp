class Solution {
public:
        vector<int> leftmostBuildingQueries(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size(), qn = queries.size();
        vector<vector<vector<int>>> que(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> h;
        vector<int> res(qn, -1);
        for (int qi = 0; qi < qn; qi++) {
            int i = queries[qi][0], j = queries[qi][1];
            if (i < j && A[i] < A[j]) {
                res[qi] = j;
            } else if (i > j && A[i] > A[j]) {
                res[qi] = i;
            } else if (i == j) {
                res[qi] = i;
            } else { 
                que[max(i, j)].push_back({max(A[i], A[j]), qi});
            }
        }
        for (int i = 0; i < n; i++) {
            while (!h.empty() && h.top()[0] < A[i]) {
                res[h.top()[1]] = i;
                h.pop();
            }
            for (auto& q : que[i]) {
                h.push(q);
            }
        }
        return res;
    }
};