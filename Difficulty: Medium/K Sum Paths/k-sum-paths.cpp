/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int ans = 0;

    void dfs(Node* root, long long currSum, long long k,
             unordered_map<long long,int> &mp) {

        if(!root) return;

        currSum += root->data;

        if(currSum == k)
            ans++;

        if(mp.find(currSum - k) != mp.end())
            ans += mp[currSum - k];

        mp[currSum]++;

        dfs(root->left, currSum, k, mp);
        dfs(root->right, currSum, k, mp);

        mp[currSum]--;   // backtrack
    }

    int countAllPaths(Node *root, int k) {

        unordered_map<long long,int> mp;
        dfs(root, 0, k, mp);

        return ans;
    }
};