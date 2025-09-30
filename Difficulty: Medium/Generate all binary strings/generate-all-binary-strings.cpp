class Solution {
  public:
    void generate(int n, string curr, vector<string> &res) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        generate(n, curr + '0', res);
        generate(n, curr + '1', res);
    }

    vector<string> binstr(int n) {
        vector<string> res;
        generate(n, "", res);
        return res;
    }
};
