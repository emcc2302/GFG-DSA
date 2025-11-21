class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    vector<ll> dijkstra(int V, int src, vector<vector<pair<int,int>>> &adj) {
        vector<ll> dist(V, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); 
            pq.pop();
            if (d != dist[u]) continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                ll w = p.second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> adj(V);

        // Build graph using only straight edges (w1)
        for (auto &e : edges) {
            int x = e[0], y = e[1], w1 = e[2];
            adj[x].push_back({y, w1});
            adj[y].push_back({x, w1});
        }

        // Dijkstra from a and b
        vector<ll> distA = dijkstra(V, a, adj);
        vector<ll> distB = dijkstra(V, b, adj);

        ll ans = distA[b];   // case: no curved edge

        // Try using each curved edge once
        for (auto &e : edges) {
            int x = e[0], y = e[1], w2 = e[3];

            if (distA[x] != INF && distB[y] != INF)
                ans = min(ans, distA[x] + w2 + distB[y]);

            if (distA[y] != INF && distB[x] != INF)
                ans = min(ans, distA[y] + w2 + distB[x]);
        }

        if (ans >= INF) return -1;
        return (int)ans;
    }
};
