class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;

        auto do_sum = [&](int idx) -> int {
            unordered_map<int, int> ctr;

            for (int i = idx; i < idx + k; ++i) {
                ctr[nums[i]]++;}

            priority_queue<pair<int, int>> pq;

            for (auto& p : ctr) {
                pq.push({p.second, p.first}); }

            int sum = 0;
            for (int i = 0; i < x && !pq.empty(); ++i) {
                sum += pq.top().second * pq.top().first;
                pq.pop();}

            return sum;};

        for (int i = 0; i <= nums.size() - k; ++i) {
            result.push_back(do_sum(i));}

        return result;}
};