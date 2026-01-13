class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int c) {
        // code here
        int n=val.size();
        vector<vector<long long>> dp(n,vector<long long>(c+1,0));
        for(int i=1;i<=c;i++){
            dp[0][i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=c;j++){
                if(j>=wt[i]) dp[i][j]=max(dp[i-1][j],dp[i][j-wt[i]]+val[i]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n-1][c];
    }
};