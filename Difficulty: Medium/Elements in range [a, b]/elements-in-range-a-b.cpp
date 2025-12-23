class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        vector<int> result;
        
        // Step 2: Process each query
        for (auto &q : queries) {
            int a = q[0];
            int b = q[1];
            
            // lower_bound: first element >= a
            int left = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            
            // upper_bound: first element > b
            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
            
            result.push_back(right - left);
        }
        
        return result;
    }
};
