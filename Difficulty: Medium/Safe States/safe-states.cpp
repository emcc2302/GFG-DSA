#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Step 1: Build the reverse graph
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
        
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adjRev[v].push_back(u); // reverse the edge
            indegree[u]++; // count original outgoing edges as indegree in reversed graph
        }
        
        // Step 2: Push all nodes with indegree 0 into queue (terminal nodes)
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        // Step 3: BFS (Kahn’s Algorithm)
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for (auto &nbr : adjRev[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        // Step 4: Sort safe nodes
        sort(safe.begin(), safe.end());
        return safe;
    }
};
