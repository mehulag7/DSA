class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp=grid;
        int n=dp.size();
        int m=dp[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int m=1e9;
                if(i==0 && j==0) continue;
                if(i>0) m=min(m,dp[i-1][j]);
                if(j>0) m=min(m,dp[i][j-1]);
                dp[i][j]+=m;
            }
        }
        return dp[n-1][m-1];
    }
};