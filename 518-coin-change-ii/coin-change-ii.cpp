class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int j = 1; j <= amount; j++) {
            if (j >= coins[0])
                dp[0][j] = dp[0][j - coins[0]];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i]){
                     long long LIMIT =1e18;
dp[i][j] += dp[i][j - coins[i]];
dp[i][j] = min(dp[i][j], LIMIT);
                }

            }
        }

        return dp[n - 1][amount];
    }
};
