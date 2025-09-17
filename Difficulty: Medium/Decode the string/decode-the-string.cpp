class Solution {
  public:
    string decodedString(string &s) {
        stack<int> numStack;       // stack for numbers
        stack<string> strStack;    // stack for strings
        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // handle multi-digit numbers
            }
            else if (c == '[') {
                numStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = numStack.top(); numStack.pop();
                string temp = curr;
                curr = strStack.top(); strStack.pop();
                while (repeat--) {
                    curr += temp;
                }
            }
            else {
                curr += c; // just a character
            }
        }
        return curr;
    }
};
