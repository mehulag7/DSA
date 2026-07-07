class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<long long>> dp(n+1,vector<long long>(W+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        if(wt[0]<=W){
            dp[0][wt[0]]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=W;j++){
                //not-take
                dp[i][j]=dp[i-1][j];
                //take
                if(j-wt[i]>=0 && dp[i-1][j-wt[i]]!=-1){
                    dp[i][j]=max(dp[i][j],val[i]+dp[i-1][j-wt[i]]);
                } 
            }
        }
        long long ans=0;
        for(int i=0;i<=W;i++){
            ans=max(ans,dp[n-1][i]);
        }
        return ans;
    }
};