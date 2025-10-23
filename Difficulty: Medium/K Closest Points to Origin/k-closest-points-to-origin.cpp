class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       
        priority_queue<pair<int, pair<int,int>>> pq;
        
        for (auto &p : points) {
            int x = p[0], y = p[1];
            int dist = x*x + y*y; 
            
            pq.push({dist, {x, y}});

            if (pq.size() > k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            ans.push_back({it.second.first, it.second.second});
        }
        
        return ans;
    }
};
