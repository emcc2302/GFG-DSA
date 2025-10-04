class Solution {
public:
    vector<string> findExpr(string &s, int target) {
        vector<string> ans;
        string path;
        dfs(s, target, 0, 0LL, 0LL, path, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }

private:
    // pos: current index in s
    // prev: the last operand value (could be negative)
    // eval: current evaluated result
    void dfs(const string &s, int target,
             int pos, long long prev, long long eval,
             string &path, vector<string> &ans) {
        int n = s.size();
        if (pos == n) {
            if (eval == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = pos; i < n; i++) {
            // disallow leading zero for multi-digit numbers
            if (i > pos && s[pos] == '0') break;

            string part = s.substr(pos, i - pos + 1);
            long long curr = stoll(part);

            int lenBefore = path.size();
            if (pos == 0) {
                // first number, no operator in front
                path += part;
                dfs(s, target, i + 1, curr, curr, path, ans);
                path.resize(lenBefore);
            } else {
                // try '+'
                path += '+';
                path += part;
                dfs(s, target, i + 1, curr, eval + curr, path, ans);
                path.resize(lenBefore);

                // try '-'
                path += '-';
                path += part;
                dfs(s, target, i + 1, -curr, eval - curr, path, ans);
                path.resize(lenBefore);

                // try '*'
                path += '*';
                path += part;
                // adjust eval to account for precedence
                long long newEval = eval - prev + (prev * curr);
                dfs(s, target, i + 1, prev * curr, newEval, path, ans);
                path.resize(lenBefore);
            }
        }
    }
};
