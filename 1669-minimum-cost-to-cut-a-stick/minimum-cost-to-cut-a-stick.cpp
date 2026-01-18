class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (j - i <= 1) return 0;   // no cut possible
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;
        for (int k = i + 1; k < j; k++) {
            ans = min(ans,
                solve(i, k, cuts, dp) +
                solve(k, j, cuts, dp) +
                cuts[j] - cuts[i]
            );
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        //return solve(0, m - 1, cuts, dp);
        for(int i=m-1;i>=0;i--){
            for(int j=i+2;j<m;j++){
                        int ans = 1e9;
        for (int k = i + 1; k < j; k++) {
            ans = min(ans,
                dp[i][k]+dp[k][j]+
                cuts[j] - cuts[i]
            );
        }
         dp[i][j] = ans;
            }
        }
        return dp[0][m-1];
    }
};
