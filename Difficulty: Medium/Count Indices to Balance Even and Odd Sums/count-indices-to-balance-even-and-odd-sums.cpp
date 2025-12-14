class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        
        int totalEven = 0, totalOdd = 0;
        
        // Calculate total even and odd index sums
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                totalEven += arr[i];
            else
                totalOdd += arr[i];
        }
        
        int leftEven = 0, leftOdd = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            // Remove current element from total
            if(i % 2 == 0)
                totalEven -= arr[i];
            else
                totalOdd -= arr[i];
            
            int newEven = leftEven + totalOdd;
            int newOdd  = leftOdd  + totalEven;
            
            if(newEven == newOdd)
                count++;
            
            // Add current element to left sums
            if(i % 2 == 0)
                leftEven += arr[i];
            else
                leftOdd += arr[i];
        }
        
        return count;
    }
};
