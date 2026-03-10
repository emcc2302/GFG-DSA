class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> nse(n);
        stack<int>st;
        long long ans =0;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
            }
        
        if(st.empty()){
            nse[i]=n;
        }
        else{
             nse[i] = st.top();
        }
        st.push(i);
        }
         for (int i = 0; i < n; i++) {
        ans += (nse[i] - i);
    }
    return ans;

    }
};