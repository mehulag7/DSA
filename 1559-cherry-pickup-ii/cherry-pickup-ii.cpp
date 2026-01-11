class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m,vector<long long>(m)));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                dp[n-1][i][j]+=grid[n-1][i]+grid[n-1][j];
                if(i==j){
                   dp[n-1][i][j]-=grid[n-1][i];
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    for(int jj=-1;jj<=1;jj++){
                        for(int kk=-1;kk<=1;kk++){
                            int r=j+jj;
                            int s=k+kk;
                            if(r>=0 && r<m && s>=0 && s<m){
                                dp[i][j][k]=max(dp[i][j][k],dp[i+1][r][s]);
                            }
                        }
                    }
                    if(j!=k){
                                    dp[i][j][k]+=grid[i][j]+grid[i][k];
                                    
                                }
                                if(j==k){
                                    dp[i][j][k]+=grid[i][j];
                                }
                }
            }
        }
        return dp[0][0][m-1];
    }

};