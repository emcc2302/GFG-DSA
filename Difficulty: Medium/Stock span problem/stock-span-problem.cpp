class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
            int n = arr.size(); 
        vector<int> span(n);  
        stack<int> st;  
    
        // Process each day's price
        for (int i = 0; i < n; i++) {
            
            // Remove elements from the stack while the current
            // price is greater than or equal to stack's top price
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
    
            // If stack is empty, all elements to the left are smaller
            // Else, top of the stack is the last greater element's index
            if (st.empty()) {
                span[i] = (i + 1);
            }
            else {
                span[i] = (i - st.top());
            }
    
            // Push the current index to the stack
            st.push(i);
        }
    
        return span;
    }
};