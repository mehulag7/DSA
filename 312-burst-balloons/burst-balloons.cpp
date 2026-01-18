class Solution {
public:
    long long solve(int i, int j, vector<int>& a, vector<vector<long long>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        long long ans = 0;
        for (int k = i; k <= j; k++) {
            ans = max(ans,
                solve(i, k - 1, a, dp) +
                solve(k + 1, j, a, dp) +
                1LL * a[i - 1] * a[k] * a[j + 1]
            );
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);

        for (int i = 1; i <= n; i++)
            a[i] = nums[i - 1];

        vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
       // return solve(1, n, a, dp);
       for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            long long ans = 0;
        for (int k = i; k <= j; k++) {
            ans = max(ans,
                dp[i][k-1]+dp[k+1][j]+1LL * a[i - 1] * a[k] * a[j + 1]);
        }
        dp[i][j]=ans;
        }
       }
       return dp[1][n];
    }
};
