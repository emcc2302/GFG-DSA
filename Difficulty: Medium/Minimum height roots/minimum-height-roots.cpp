class Solution {
public:
    vector<int> minHeightRoot(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        // Build graph
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Push all leaf nodes
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remainingNodes = n;

        // Remove leaves layer by layer
        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;

            while (size--) {
                int node = q.front();
                q.pop();

                for (auto neighbor : adj[node]) {
                    degree[neighbor]--;

                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};