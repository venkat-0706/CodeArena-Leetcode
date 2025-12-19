
class UnionFind {    
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        return (x == root[x])?x: root[x]=Find(root[x]);
    }

    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)  return;
        if (rank[rX] > rank[rY]) swap(rX, rY);   
        root[rX] = rY;
        if (rank[rX]==rank[rY]) rank[rY]++;
    }
    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }

    void reset(int x){
        root[x]=x;
        rank[x]=1;
    }
};

class Solution {
public:
    using int2=pair<int, int>;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        vector<int2> meet_time[100001];
        int tMax=-1;
        for(auto& meet: meetings){
            int x=meet[0], y=meet[1], t=meet[2];
            meet_time[t].emplace_back(x, y);
            tMax=max(tMax, t);
        }
        UnionFind uf(n);
        uf.Union(0, firstPerson);
        for (int t=0; t<=tMax; t++){
            for(auto& [x, y]: meet_time[t])
                uf.Union(x, y);
            for(auto& [x, y]: meet_time[t]){
                if (!uf.connected(0, x)){
                    uf.reset(x);
                    uf.reset(y);
                }
            }
        }
        vector<int> list={0};
        for(int i=1; i<n; i++)
            if (uf.connected(0, i)) list.push_back(i);

        return list;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();