class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for (int i=0; i<s.size(); i++) {

        // if current character is close parenthesis ')'
        if (s[i] == ')') {
            char top = st.top();
            st.pop();

            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;
            
            while (!st.empty() and top != '(') {

                // Check for operators in expression
                if (top == '+' or top == '-' or
                    top == '*' or top == '/')
                    flag = false;

                // Fetch top element of stack
                top = st.top();
                st.pop();
            }

            // If operators not found
            if (flag == true)
                return true;
        }
        else
            st.push(s[i]); 
    }
    return false;
    }
};
