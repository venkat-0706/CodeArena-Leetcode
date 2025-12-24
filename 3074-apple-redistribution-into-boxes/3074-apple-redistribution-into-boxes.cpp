class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(cap.begin(), cap.end(), greater<int>());

        int res = 0;
        while (sum > 0)
            sum -= cap[res++];

        return res;
    }
};
