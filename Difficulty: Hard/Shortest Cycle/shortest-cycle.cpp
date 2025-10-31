class Solution {
public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;

        for (int s = 0; s < V; ++s) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);

            queue<int> q;
            dist[s] = 0;
            q.push(s);

            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        // not visited
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if (v != parent[u]) {
                        // found a cycle via u->v
                        int cycle_len = dist[u] + dist[v] + 1;
                        ans = min(ans, cycle_len);
                    }
                }
            }
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};
