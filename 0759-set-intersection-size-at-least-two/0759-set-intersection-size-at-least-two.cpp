class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [&](const vector<int> &A, const vector<int> &B){
            return A[0] > B[0];
        });
        int x = 1e9;
        int y = 1e9;

        int ans = 0;
        for(auto range : intervals){
            int l = range[0];
            int r = range[1];

            int need = 2;

            if(x <= r) need -= 1;
            if(y <= r) need -= 1;

            if(need == 0) continue;
            if(need == 1){
                if(x != l){
                    y = l;
                }
                else{
                    y = l + 1;
                }
                if(y < x){
                    swap(x, y);
                }
                ans += 1;
            }
            else{
                x = l;
                y = l + 1;
                ans += 2;
            }
        }
        return ans;
    }
};