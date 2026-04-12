class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        
        // Check if all digits are 9
        bool all9 = true;
        for(int i = 0; i < n; i++) {
            if(num[i] != 9) {
                all9 = false;
                break;
            }
        }
        
        // If all 9 → return 100...001
        if(all9) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }
        
        vector<int> result = num;
        
        // Step 1: Mirror left to right
        int i = n/2 - 1;
        int j = (n % 2) ? n/2 + 1 : n/2;
        
        bool leftSmaller = false;
        
        while(i >= 0 && result[i] == result[j]) {
            i--;
            j++;
        }
        
        if(i < 0 || result[i] < result[j])
            leftSmaller = true;
        
        // Mirror
        while(i >= 0) {
            result[j] = result[i];
            i--;
            j++;
        }
        
        // Step 2: If mirrored number not bigger
        if(leftSmaller) {
            int carry = 1;
            
            if(n % 2 == 1) {
                int mid = n/2;
                result[mid] += carry;
                carry = result[mid] / 10;
                result[mid] %= 10;
                
                i = mid - 1;
                j = mid + 1;
            }
            else {
                i = n/2 - 1;
                j = n/2;
            }
            
            // Propagate carry
            while(i >= 0) {
                result[i] += carry;
                carry = result[i] / 10;
                result[i] %= 10;
                
                result[j] = result[i];
                
                i--;
                j++;
            }
        }
        
        return result;
    }
};
