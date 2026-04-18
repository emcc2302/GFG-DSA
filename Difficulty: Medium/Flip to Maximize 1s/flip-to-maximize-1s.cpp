class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        //using kadane's algo
        //if maximum sum is -ve then reset it with 0
        
        int countOnes=0;
        for (int x:arr){
            if(x==1) countOnes++;
        }
        
         // Step 2: apply Kadane on transformed values
        int maxGain = 0, currSum = 0;
        
        for (int x : arr) {
            int val = (x == 0) ? 1 : -1;  // transformation
            
            currSum = max(val, currSum + val);
            maxGain = max(maxGain, currSum);
        }
        
        // Step 3: result
        return countOnes + maxGain;
    }
};