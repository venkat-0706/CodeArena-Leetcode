class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalEnergy = 0;
        for (int b : batteries) totalEnergy += b;

        sort(batteries.begin(), batteries.end());

        for (int i = batteries.size() - 1; i >= 0; i--) {
            if (batteries[i] > totalEnergy / n) {
                totalEnergy -= batteries[i];
                n--;
            } else break;
        }

        return totalEnergy / n;
    }
};