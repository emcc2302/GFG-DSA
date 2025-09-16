#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        
        for (string &token : arr) {
            // If token is operator
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;

                if (token == "+") res = a + b;
                else if (token == "-") res = a - b;
                else if (token == "*") res = a * b;
                else if (token == "/") {
                    // Floor division handling
                    res = a / b;
                    if ((a % b != 0) && ((a < 0) ^ (b < 0))) res--;
                }
                else if (token == "^") res = pow(a, b);

                st.push(res);
            } 
            else {
                // Operand (number), convert string to int
                st.push(stoll(token));
            }
        }
        
        return (int)st.top();
    }
};
