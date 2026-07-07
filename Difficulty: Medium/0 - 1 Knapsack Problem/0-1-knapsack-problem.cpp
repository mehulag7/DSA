class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<long long>> dp(n+1,vector<long long>(W+1,0));
        for(int i=wt[0];i<=W;i++){
            dp[0][i]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=W;j++){
                //not-take
                dp[i][j]=dp[i-1][j];
                //take
                if(j-wt[i]>=0){
                    dp[i][j]=max(dp[i][j],val[i]+dp[i-1][j-wt[i]]);
                } 
            }
        }
        return dp[n-1][W];
    }
};