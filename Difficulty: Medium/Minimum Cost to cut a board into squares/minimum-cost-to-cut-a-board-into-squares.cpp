class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort in descending order
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int i = 0, j = 0;
        int hSegments = 1, vSegments = 1;
        long long cost = 0;
        
        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                // Take vertical cut
                cost += 1LL * x[i] * hSegments;
                vSegments++;
                i++;
            } else {
                // Take horizontal cut
                cost += 1LL * y[j] * vSegments;
                hSegments++;
                j++;
            }
        }
        
        // Remaining vertical cuts
        while (i < x.size()) {
            cost += 1LL * x[i] * hSegments;
            vSegments++;
            i++;
        }
        
        // Remaining horizontal cuts
        while (j < y.size()) {
            cost += 1LL * y[j] * vSegments;
            hSegments++;
            j++;
        }
        
        return (int)cost;
    }
};
