class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long>> prev(2, vector<long long>(3, 0));
        vector<vector<long long>> curr(2, vector<long long>(3, 0));
        for (int day = n - 1; day >= 0; day--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int t = 0; t <= 1; t++) {  // only 0 and 1
                    if (buy) {
                        curr[buy][t] = max(
                            -prices[day] + prev[0][t],
                            prev[1][t]
                        );
                    } else {
                        curr[buy][t] = max(
                            prices[day] + prev[1][t + 1],
                            prev[0][t]
                        );
                    }
                }
            }
            prev=curr;
        }
        return prev[1][0];
    }
};
