class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();   // number of vertices
        
        vector<int> vis(V, 0);
        queue<int> q;
        vector<int> bfss;
        
        vis[0] = 1;
        q.push(0);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            bfss.push_back(node);
            
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfss;
    }
};