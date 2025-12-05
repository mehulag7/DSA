class Solution {
  public:
    int minCost(vector<int>& h) {
        // Code here
        int n=h.size();
        vector<long long> v(n,1e9);
        v[0]=0;
        if(n>1)   v[1]=abs(h[0]-h[1]);
        else return v[0];
        for(int i=2;i<n;i++){
            v[i]=min(v[i-2]+abs(h[i]-h[i-2]),v[i-1]+abs(h[i]-h[i-1]));
        }
        return v[n-1];
    }
};