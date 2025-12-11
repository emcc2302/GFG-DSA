class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        int m = arr.size();
        
        if (m == 1) {
            return {1, arr[0] - 1};
        }
        int n = (1 + sqrt(1 + 8*m)) / 2;
        
        vector<int> res(n);
        long long a0 = ( (long long)arr[0] + arr[1] - arr[n - 1] ) / 2;
        res[0] = a0;
        res[1] = arr[0] - res[0];
        res[2] = arr[1] - res[0];
        
        for (int k = 3; k < n; k++) {
            res[k] = arr[k - 1] - res[0];
        }
        
        return res;
    }
};
