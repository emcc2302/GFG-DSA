class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
         int n = s.size();
    stack<char> st;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];

        // Remove larger digits when possible
        while (!st.empty() && k > 0 && st.top() > c) {
            st.pop();
            k -= 1;
        }

        if (!st.empty() || c != '0')
            st.push(c);
    }

    // Remove remaining digits if any
    while (!st.empty() && k--)
        st.pop();

    if (st.empty())
        return "0";

    // Build result from stack
    while (!st.empty()) {
        s[n - 1] = st.top();
        st.pop();
        n -= 1;
    }

    return s.substr(n);

    }
};