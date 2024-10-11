class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> order(n);
        for (int i = 0; i < n; ++i) order[i] = i;

        sort(order.begin(), order.end(), [&times](int a, int b) {
            return times[a][0] < times[b][0];
        });

        priority_queue<int, vector<int>, greater<int>> emptySeats;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> takenSeats;

        for (int i = 0; i < n; ++i) emptySeats.push(i);

        for (int i : order) {
            int arrival = times[i][0], leave = times[i][1];

            while (!takenSeats.empty() && takenSeats.top().first <= arrival) {
                emptySeats.push(takenSeats.top().second);
                takenSeats.pop();
            }

            int seat = emptySeats.top();
            emptySeats.pop();

            if (i == targetFriend) return seat;

            takenSeats.push({leave, seat});
        }

        return -1;  
    }
};