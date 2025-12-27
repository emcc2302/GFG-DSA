class Solution {
  public:
  
    // returns number of donuts a chef with
    // rank r can make in time t
    int donutsByChef(int t, int r) {
        double D = 1.0 + 8.0 * t / r;
        return int((-1.0 + sqrt(D)) / 2.0);
    }
    
    // Checks if all chefs can make
    // at least n donuts in time t
    bool canMake(vector<int>& ranks, int n, int t) {
        int total = 0;
        for (int r : ranks) {
            total += donutsByChef(t, r);
            if (total >= n)
                return true;
        }
        return false;
    }
    
    // binary search on time to
    // find minimum time needed
    int minTime(vector<int>& ranks, int n) {
        int rmin = *min_element(ranks.begin(), ranks.end());
        int hi = rmin * n * (n + 1) / 2;
        int lo = 0, ans = hi;
    
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(ranks, n, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};