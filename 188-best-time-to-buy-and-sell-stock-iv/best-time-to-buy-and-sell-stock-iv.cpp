class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2 * k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2 * k; j++) {
                if (j % 2 == 0) {  // buy
                    dp[i][j] = max(
                        -prices[i] + dp[i + 1][j + 1],
                        dp[i + 1][j]
                    );
                } else {           // sell
                    dp[i][j] = max(
                        prices[i] + dp[i + 1][j + 1],
                        dp[i + 1][j]
                    );
                }
            }
        }
        return dp[0][0];
    }
};
