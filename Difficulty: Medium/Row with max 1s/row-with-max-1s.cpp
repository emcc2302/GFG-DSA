class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int maxCount = 0; 
        int ans = -1;
        
        for(int i = 0; i < n; i++) {
            // binary search for first '1'
            int low = 0, high = m - 1;
            int firstOne = -1;
            
            while(low <= high) {
                int mid = (low + high) / 2;
                if(arr[i][mid] == 1) {
                    firstOne = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            if(firstOne != -1) {
                int countOnes = m - firstOne;
                if(countOnes > maxCount) {
                    maxCount = countOnes;
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};
