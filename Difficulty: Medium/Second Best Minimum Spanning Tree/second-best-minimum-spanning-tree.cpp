class Solution {
public:

    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if(a == b) return false;
            if(rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
            return true;
        }
    };

    int secondMST(int V, vector<vector<int>> &edges) {
        vector<array<int, 3>> e;
        for(auto &x : edges) e.push_back({x[0], x[1], x[2]});
        
        sort(e.begin(), e.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        DSU dsu(V);
        int nE = e.size();
        vector<bool> used(nE, false);
        vector<vector<pair<int,int>>> mst(V);

        int mstW = 0, cnt = 0;

        for(int i = 0; i < nE; i++) {
            auto &[u, v, w] = e[i];
            if(dsu.unite(u, v)) {
                mstW += w;
                used[i] = true;
                cnt++;
                mst[u].push_back({v, w});
                mst[v].push_back({u, w});
            }
        }

        if(cnt != V - 1) return -1;

        int ans = INT_MAX;

        vector<int> parent(V), parentW(V);

        auto findPath = [&](int src, int dst) {
            vector<bool> vis(V, false);
            queue<int> q;
            q.push(src);
            vis[src] = true;
            parent[src] = -1;

            while(!q.empty()) {
                int u = q.front(); q.pop();
                if(u == dst) return true;
                for(auto &p : mst[u]) {
                    int v = p.first, w = p.second;
                    if(!vis[v]) {
                        vis[v] = true;
                        parent[v] = u;
                        parentW[v] = w;
                        q.push(v);
                    }
                }
            }
            return false;
        };

        for(int i = 0; i < nE; i++) {
            if(used[i]) continue;
            int u = e[i][0], v = e[i][1], w = e[i][2];

            if(!findPath(u, v)) continue;

            int cur = v;
            while(cur != u) {
                int droppedEdgeWeight = parentW[cur];
                int newWeight = mstW + w - droppedEdgeWeight;
                if(newWeight > mstW && newWeight < ans)
                    ans = newWeight;
                cur = parent[cur];
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
