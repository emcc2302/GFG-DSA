#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int m = pat.size();
        int n = tar.size();
        if (n > m) return false;

        // positions[char][parity] -> sorted list of indices
        vector<int> positions[26][2];
        for (int i = 0; i < m; ++i) {
            int c = pat[i] - 'a';
            positions[c][i % 2].push_back(i);
        }

        // helper: find next index > cur in list (binary search)
        auto next_index = [&](const vector<int> &lst, int cur) -> int {
            auto it = upper_bound(lst.begin(), lst.end(), cur);
            if (it == lst.end()) return -1;
            return *it;
        };

        // Try both starting parities (0 = even index, 1 = odd index)
        for (int start_par = 0; start_par <= 1; ++start_par) {
            // first character must appear at some index with parity = start_par
            int ch0 = tar[0] - 'a';
            const vector<int> &start_list = positions[ch0][start_par];
            if (start_list.empty()) continue; // no candidate starting index with this parity

            // pick earliest possible starting position (greedy)
            int cur = start_list.front();

            bool ok = true;
            for (int k = 1; k < n; ++k) {
                int need_par = start_par ^ (k % 2); // parity alternates
                int ch = tar[k] - 'a';
                int nxt = next_index(positions[ch][need_par], cur);
                if (nxt == -1) { ok = false; break; }
                cur = nxt;
            }
            if (!ok) continue;

            // suffix after last matched index must have even length
            int suffix_len = m - cur - 1;
            if ((suffix_len % 2) == 0) return true;
        }

        return false;
    }
};
