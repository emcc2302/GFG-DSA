class Solution {
  public:
    void permutations(vector<vector<int>>& res, vector<int> arr, int idx) {
        if (idx == arr.size()) {
            res.push_back(arr);
            return;
        }
    
        // Permutations made by swapping each element
        // starting from index `idx`
        for (int i = idx; i < arr.size(); i++) {
          
            // Swapping
            swap(arr[idx], arr[i]);
    
            // Recursive call to create permutations 
            // for the next element
            permutations(res, arr, idx + 1);
    
            // Backtracking
            swap(arr[idx], arr[i]);
        }
    }
    
    // Function to get the permutations
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        permutations(res, arr, 0);
        return res;
    }
};