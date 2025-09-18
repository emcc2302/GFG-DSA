class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);   // Initialize result with -1
        stack<int> st;            // Stack to keep indices

        // Traverse the array twice (simulate circular behavior)
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;   // Circular index

            // While current element is greater than top of stack
            while (!st.empty() && arr[idx] > arr[st.top()]) {
                ans[st.top()] = arr[idx];
                st.pop();
            }

            // Only push first n indices (avoid infinite loop)
            if (i < n) {
                st.push(idx);
            }
        }
        return ans;
    }
};
