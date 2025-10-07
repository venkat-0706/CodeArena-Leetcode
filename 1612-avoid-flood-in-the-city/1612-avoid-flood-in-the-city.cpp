class UnionFind {
public:
    vector<int> parent;

    UnionFind(int size) : parent(size + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (i == parent[i])
            return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int i) { parent[i] = find(i + 1); }
};

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rain) {
        int n = rain.size();
        UnionFind uf(n + 1);
        unordered_map<int, int> map;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++) {
            int lake = rain[i];
            if (lake == 0) continue;

            res[i] = -1;
            uf.unite(i);

            if (map.find(lake) != map.end()) {
                int prev = map[lake];
                int dry = uf.find(prev + 1);

                if (dry >= i) return {};

                res[dry] = lake;
                uf.unite(dry);
                map[lake] = i;
            } else {
                map[lake] = i;
            }
        }

        return res;
    }
};