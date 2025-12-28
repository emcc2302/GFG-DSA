class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        if(n>m) return kthElement(b,a,k);
        int low = max(0, k-m), high = min(k,n);
        while(low<=high){
            int m1 = (low+high)/2;
            int m2 = k-m1;
            int l1 = (m1==0? INT_MIN : a[m1-1]);
            int r1 = (m1==n ? INT_MAX : a[m1]);
            int l2 = (m2==0? INT_MIN : b[m2-1]);
            int r2 = (m2==m ? INT_MAX : b[m2]);
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }
            if(l1>r2) high = m1-1;
            else low = m1+1;
        }
        return 0;
    }
};