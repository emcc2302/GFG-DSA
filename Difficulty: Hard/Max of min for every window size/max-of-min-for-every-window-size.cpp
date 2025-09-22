#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n), ans(n+1, 0);

        // Step 1: Find previous smaller element
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Step 2: Find next smaller element
        while (!st.empty()) st.pop();
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Step 3: For each element, find length of window where it's min
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }

        // Step 4: Fill remaining entries
        for (int i = n-1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i+1]);
        }

        // Result (ignore index 0)
        vector<int> res(n);
        for (int i = 1; i <= n; i++)
            res[i-1] = ans[i];

        return res;
    }
};
