class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        
        int m1[2] = {INT_MAX, INT_MAX};
        int m2[2] = {INT_MAX, INT_MAX};

        for (int x : nums) {
            sum += x;
            int r = x % 3;

            if (r == 1) {
                if (x < m1[0]) { m1[1] = m1[0]; m1[0] = x; }
                else if (x < m1[1]) m1[1] = x;
            }
            else if (r == 2) {
                if (x < m2[0]) { m2[1] = m2[0]; m2[0] = x; }
                else if (x < m2[1]) m2[1] = x;
            }
        }

        if (sum % 3 == 0) return sum;

        int rem = sum % 3;

        int ans = 0;

        if (rem == 1) {
            int remove1 = m1[0];
            int remove2 = (m2[0] == INT_MAX || m2[1] == INT_MAX) ? INT_MAX : m2[0] + m2[1];
            ans = sum - min(remove1, remove2);
        } 
        else {
            int remove1 = m2[0];
            int remove2 = (m1[0] == INT_MAX || m1[1] == INT_MAX) ? INT_MAX : m1[0] + m1[1];
            ans = sum - min(remove1, remove2);
        }

        return ans < 0 ? 0 : ans;
    }
};