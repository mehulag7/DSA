class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(2, vector<long long>(3, 0))
        );

        for (int day = n - 1; day >= 0; day--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int t = 0; t <= 1; t++) {  // only 0 and 1
                    if (buy) {
                        dp[day][buy][t] = max(
                            -prices[day] + dp[day + 1][0][t],
                            dp[day + 1][1][t]
                        );
                    } else {
                        dp[day][buy][t] = max(
                            prices[day] + dp[day + 1][1][t + 1],
                            dp[day + 1][0][t]
                        );
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};
