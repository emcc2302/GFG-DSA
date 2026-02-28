class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n = arr1.size(), m = arr2.size();
    
        int l = 0, r = m - 1;
        int mini = INT_MAX;
        vector<int> res(2);
    
        while (l < n && r >= 0)
        {
            int sum = arr1[l] + arr2[r];
            int diff = abs(sum - x);
   
            if (diff < mini)
            {
                mini = diff;
                res[0] = arr1[l];
                res[1] = arr2[r];
            }

            if (sum > x)
                r--;
            else
                l++;
        }
    
        return res;
    }
};