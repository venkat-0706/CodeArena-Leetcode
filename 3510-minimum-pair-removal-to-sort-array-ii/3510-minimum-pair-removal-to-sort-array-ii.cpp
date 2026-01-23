using ll = long long;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<ll> a(n);
        for (int i = 0; i < n; i++) a[i] = nums[i];
        
        // maintain adjacent pairs {sum, index}
        set<pair<ll, int>> s;

        // double-linked list
        vector<int> nxt(n);
        vector<int> pre(n);
        for (int i = 0; i < n; i++) nxt[i] = i + 1;
        for (int i = 0; i < n; i++) pre[i] = i - 1;

        // insert all pairs into set
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) cnt++;
            s.insert({a[i] + a[i + 1], i});
        }
        
        // simulate the process
        int ans = 0;
        while (cnt > 0) {
            int i = s.begin()->second;
            int j = nxt[i];
            int p = pre[i];
            int q = nxt[j];

            // pair {i, j}
            if (a[i] > a[j]) cnt--;
            if (p >= 0) {
                // pair {p, i}
                if (a[p] > a[i] && a[p] <= a[i] + a[j]) {
                    cnt--;
                }
                else if (a[p] <= a[i] && a[p] > a[i] + a[j]) {
                    cnt++;
                }
            }
            if (q < n) {
                // pair {j, q}
                if (a[q] >= a[j] && a[q] < a[i] + a[j]) {
                    cnt++;
                }
                else if (a[q] < a[j] && a[q] >= a[i] + a[j]) {
                    cnt--;
                }
            }

            // remove outdated pairs & add new pairs
            s.erase(s.begin());
            if (p >= 0) {
                s.erase({a[p] + a[i], p});
                s.insert({a[p] + a[i] + a[j], p});
            }
            if (q < n) {
                s.erase({a[j] + a[q], j});
                s.insert({a[i] + a[j] + a[q], i});
                pre[q] = i;
            }
            nxt[i] = q;
            a[i] = a[i] + a[j];
            ans++;
        }
        
        return ans;
    }
};