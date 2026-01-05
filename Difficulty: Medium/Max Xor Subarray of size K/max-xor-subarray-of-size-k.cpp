class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();     
        int xorr = 0;
        for(int i = 0; i < k; i++) {
            xorr ^= arr[i];
        }
        
        int maxi = xorr;
        
        // Slide the window
        for(int i = k; i < n; i++) {
            xorr ^= arr[i]; // right element xor kiye
            xorr ^= arr[i - k]; //left ko unxor kiye
            maxi = max(maxi, xorr);
        }
        
        return maxi;
        
    }
};