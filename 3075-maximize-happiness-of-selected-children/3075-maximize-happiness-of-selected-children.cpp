class Solution {
public:
    long long maximumHappinessSum(vector<int>& christmasJoy, int gifts) {
        sort(christmasJoy.begin(), christmasJoy.end(), greater<int>());
        long long totalJoy = 0;
        for (int turn = 0; turn < gifts; ++turn) {
            int currentJoy = christmasJoy[turn] - turn;
            if (currentJoy <= 0)
                break;
            totalJoy += currentJoy;
        }
        
        return totalJoy;
    }
};