class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<int> adj[n]; 
        vector<int> indegree(n, 0);
        
        // Build adjacency list and indegree array
        for (auto &pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            
            for (auto v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        
        // If we couldn’t include all courses, there’s a cycle
        if (order.size() != n)
            return {};
        
        return order;
    }
};
