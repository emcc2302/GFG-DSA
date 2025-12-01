#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];
    int cnt; // number of numbers that pass through this node
    TrieNode() {
        child[0] = child[1] = nullptr;
        cnt = 0;
    }
};

class Solution {
public:
    int cntPairs(vector<int>& arr, int k) {
        if (k == 0) return 0; // no pair can have XOR < 0

        const int MAXB = 16; // enough for values up to 5*10^4 (<= 2^16)
        TrieNode* root = new TrieNode();

        auto insert = [&](int x) {
            TrieNode* node = root;
            for (int i = MAXB; i >= 0; --i) {
                int b = (x >> i) & 1;
                if (!node->child[b]) node->child[b] = new TrieNode();
                node = node->child[b];
                node->cnt++;
            }
        };

        // count how many previously inserted numbers y satisfy (x ^ y) < k
        auto countLessThanK = [&](int x) -> long long {
            TrieNode* node = root;
            long long res = 0;
            for (int i = MAXB; i >= 0 && node; --i) {
                int xb = (x >> i) & 1;
                int kb = (k >> i) & 1;
                if (kb == 1) {
                    // if we pick child = xb then xor-bit = 0 < 1 -> all numbers in that subtree are valid
                    if (node->child[xb]) res += node->child[xb]->cnt;
                    // then we must follow the branch that makes xor-bit = 1 to continue check (child = 1^xb)
                    node = node->child[xb ^ 1];
                } else {
                    // kb == 0 => must follow branch that makes xor-bit = 0 (child = xb)
                    node = node->child[xb];
                }
            }
            return res;
        };

        long long total = 0;
        // insert first element then for each subsequent compute counts (or do query before insert to avoid counting self-pair)
        for (size_t i = 0; i < arr.size(); ++i) {
            // query how many previous numbers pair with arr[i] to give xor < k
            if (i > 0) total += countLessThanK(arr[i]);
            // insert current number for future queries
            insert(arr[i]);
        }

        // clean up trie (optional in contest settings)
        // (left out for brevity)

        return (int)total;
    }
};
