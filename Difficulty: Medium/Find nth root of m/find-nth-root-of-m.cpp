class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int ans=-1;
        int low=0,high=m;
        while(low<=high){
            int mid=(low+high)/2;
            int p=1;
            for(int i=0;i<n;i++) p*=mid;
            if(p==m){
                ans=mid;
                return ans;
            }
            else if(p<m){
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};