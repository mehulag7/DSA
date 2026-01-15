class Solution {
public:
    long long solve(string &s, string &t, int n, int m,
                    vector<vector<long long>> &dp) {

        if (m == 0) return 1;   // t matched
        if (n == 0) return 0;   // s exhausted

        if (dp[n][m] != -1) return dp[n][m];

        long long ans = solve(s, t, n - 1, m, dp); // skip s[n-1]

        if (s[n - 1] == t[m - 1]) {
            ans += solve(s, t, n - 1, m - 1, dp);
        }

        return dp[n][m] = ans;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(m + 1, -1));
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        long long p=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               dp[i][j]=dp[i-1][j];
               if(s[i-1]==t[j-1]) {
                p=dp[i-1][j-1];
                dp[i][j]+=(int)p;
               }
            }
        }
        return dp[n][m];
    }
};
