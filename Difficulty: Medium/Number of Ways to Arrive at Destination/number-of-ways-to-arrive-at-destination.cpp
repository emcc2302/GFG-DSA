#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const long long MOD = 1'000'000'007LL;
        const long long INF = (long long)1e18;

        // build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // Dijkstra
        vector<long long> dist(V, INF);
        vector<long long> ways(V, 0);
        dist[0] = 0;
        ways[0] = 1;

        using pli = pair<long long,int>; // (distance, node)
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto &pr : adj[u]) {
                int v = pr.first;
                int w = pr.second;
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                } else if (nd == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return (int)(ways[V-1] % MOD);
    }
};
