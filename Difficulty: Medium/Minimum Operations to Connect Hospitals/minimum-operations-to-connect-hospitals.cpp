class Solution {
public:
    int findParent(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent); 
    }
    
    void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = findParent(a, parent);
        b = findParent(b, parent);
        if (a != b) {
            if (rank[a] < rank[b]) parent[a] = b;
            else if (rank[b] < rank[a]) parent[b] = a;
            else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }
    
    int minConnect(int V, vector<vector<int>>& edges) {
        int E = edges.size();
        
        // if total edges less than V-1, impossible
        if (E < V - 1) return -1;
        
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;
        
        // union-find to find connected components
        for (auto &e : edges) {
            unionSet(e[0], e[1], parent, rank);
        }
        
        // count distinct parents = number of components
        int components = 0;
        for (int i = 0; i < V; i++) {
            if (parent[i] == i) components++;
        }
        
        // to connect k components we need (k-1) operations
        return components - 1;
    }
};
