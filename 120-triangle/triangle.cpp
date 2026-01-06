class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp=triangle;
        int n=dp.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<i+1;j++){
              if(j!=i && j>0)  dp[i][j]+=min(dp[i-1][j],dp[i-1][j-1]);
              else{
                if(j==0){
                    dp[i][j]+=dp[i-1][j];
                }
                else{
                    dp[i][j]+=dp[i-1][j-1];
                }
              }
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};