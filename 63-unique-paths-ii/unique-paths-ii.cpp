class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m=Grid.size();
        int n=Grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
       if(Grid[0][0]!=1)   dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(Grid[i][j]==1) continue;
                else{
                    if(i>0) dp[i][j]+=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};