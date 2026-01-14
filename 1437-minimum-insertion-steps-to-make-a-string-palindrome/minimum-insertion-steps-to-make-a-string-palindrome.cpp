class Solution {
public:
    int minInsertions(string s) {
        string p=s;
        reverse(p.begin(),p.end());
        int n=s.length();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]) dp[i][j]=1+dp[i-1][j-1];
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i][j]);
            }

        }
        long long ans=n-dp[n][n];

        return ans;
    }
};