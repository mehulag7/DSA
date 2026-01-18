class Solution {
  public:
  int solve(int i,int j,vector<int> &a, vector<vector<int>> &dp){
      if(i>=j) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      int ans=1e9;
      for(int ii=i;ii<j;ii++){
          ans=min(ans,solve(i,ii,a,dp)+solve(ii+1,j,a,dp)+a[i-1]*a[ii]*a[j]);
      }
      return dp[i][j]=ans;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(1,n-1,arr,dp);
    }
};