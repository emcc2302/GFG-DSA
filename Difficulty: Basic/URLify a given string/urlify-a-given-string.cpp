class Solution {
  public:
    string URLify(string &s) {
        // code here
        string result = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            result += "%20";
        } else {
            result += s[i];
        }
    }
    return result;
    }
};