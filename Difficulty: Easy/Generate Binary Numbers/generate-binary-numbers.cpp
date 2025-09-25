class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> result;
        queue<string> q;
        q.push("1");
        
        while (n--) {
            string s = q.front();
            q.pop();
            result.push_back(s);
            
            // generate next numbers
            q.push(s + "0");
            q.push(s + "1");
        }
        
        return result;
    }
};
