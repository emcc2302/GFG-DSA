class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        // parent map: map each row and each column to a union-find node
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;

        function<int(int)> findp = [&](int x) {
            if (parent[x] != x) parent[x] = findp(parent[x]);
            return parent[x];
        };

        auto unite = [&](int x, int y) {
            int px = findp(x), py = findp(y);
            if (px == py) return;
            // union by rank
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        };

        // assign union-find nodes for each row and each column
        for (auto &s : stones) {
            int r = s[0], c = s[1] + 10001;  
            // shift columns so they don't clash with rows
            if (!parent.count(r)) {
                parent[r] = r;
                rank[r] = 0;
            }
            if (!parent.count(c)) {
                parent[c] = c;
                rank[c] = 0;
            }
            unite(r, c);
        }

        // count distinct connected components (unique roots)
        unordered_set<int> comps;
        for (auto &kv : parent) {
            comps.insert(findp(kv.first));
        }

        // result = total stones - number of components
        return n - comps.size();
    }
};
