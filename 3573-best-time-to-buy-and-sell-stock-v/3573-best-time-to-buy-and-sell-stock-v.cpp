
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<long long> prev(n, 0), curr(n, 0);

        for (int t = 1; t <= k; t++) {
            long long bestLong = -prices[0];
            long long bestShort = prices[0];
            curr[0] = 0;

            for (int i = 1; i < n; i++) {
                long long res = curr[i - 1];
                res = max(res, (long long)prices[i] + bestLong);
                res = max(res, - (long long)prices[i] + bestShort);
                curr[i] = res;

                bestLong = max(bestLong, prev[i - 1] - (long long)prices[i]);
                bestShort = max(bestShort, prev[i - 1] + (long long)prices[i]);
            }
            prev.swap(curr);
        }

        return prev[n - 1];
    }
};