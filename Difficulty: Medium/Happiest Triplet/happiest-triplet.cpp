class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        int i = 0, j = 0, k = 0;
        int n = a.size();
        
        int bestDiff = INT_MAX;
        long long bestSum = LLONG_MAX;
        vector<int> ans(3);
        
        while (i < n && j < n && k < n) {
            int x = a[i], y = b[j], z = c[k];
            
            int curMax = max({x, y, z});
            int curMin = min({x, y, z});
            int diff = curMax - curMin;
            long long sum = 1LL * x + y + z;
            
            if (diff < bestDiff || (diff == bestDiff && sum < bestSum)) {
                bestDiff = diff;
                bestSum = sum;
                ans = {x, y, z};
            }
            
            if (curMin == x) i++;
            else if (curMin == y) j++;
            else k++;
        }
        
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};
