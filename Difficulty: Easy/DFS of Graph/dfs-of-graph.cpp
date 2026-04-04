class Solution {
    
private:
    void dfss(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &list) {
        vis[node] = 1;
        list.push_back(node);
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfss(it, adj, vis, list);
            }
        }
    }
    
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> list;
        
        dfss(0, adj, vis, list);
        
        return list;
    }
};