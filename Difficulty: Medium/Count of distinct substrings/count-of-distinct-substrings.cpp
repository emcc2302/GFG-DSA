class Solution {
public:
    struct State {
        int link, len;
        int next[26];
        State() {
            link = -1;
            len = 0;
            fill(next, next + 26, -1);
        }
    };

    int countSubs(string& s) {
        int n = s.size();
        vector<State> st(2 * n);
        int last = 0, sz = 1;
        
        for(char c : s) {
            int cur = sz++;
            st[cur].len = st[last].len + 1;
            int p = last;
            int cidx = c - 'a';
            
            while(p != -1 && st[p].next[cidx] == -1) {
                st[p].next[cidx] = cur;
                p = st[p].link;
            }
            
            if (p == -1) {
                st[cur].link = 0;
            } else {
                int q = st[p].next[cidx];
                if (st[p].len + 1 == st[q].len) {
                    st[cur].link = q;
                } else {
                    int clone = sz++;
                    st[clone] = st[q];
                    st[clone].len = st[p].len + 1;
                    
                    while(p != -1 && st[p].next[cidx] == q) {
                        st[p].next[cidx] = clone;
                        p = st[p].link;
                    }
                    st[q].link = st[cur].link = clone;
                }
            }
            last = cur;
        }
        
        long long ans = 0;
        for(int i = 1; i < sz; i++) {
            ans += st[i].len - st[st[i].link].len;
        }
        return ans;
    }
};
