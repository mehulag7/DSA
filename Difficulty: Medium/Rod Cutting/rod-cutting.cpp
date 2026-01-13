// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<long long>> dp(n, vector<long long>(n + 1, 0));

        // Base case: only rod of length 1
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j * price[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                long long notTake = dp[i - 1][j];
                long long take = 0;
                if (j >= i + 1)
                    take = price[i] + dp[i][j - (i + 1)];

                dp[i][j] = max(notTake, take);
            }
        }

        return dp[n - 1][n];
    }
};