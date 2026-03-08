class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        
        int n = arr.size();
        unordered_set<long long> st;

        // Step 1: store squares
        for(int i = 0; i < n; i++) {
            long long val = 1LL * arr[i] * arr[i];
            st.insert(val);
        }

        // Step 2: check pairs
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                
                long long sum =
                    1LL * arr[i] * arr[i] +
                    1LL * arr[j] * arr[j];

                if(st.count(sum)) return true;
            }
        }

        return false;
    }
};