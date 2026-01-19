class Solution {
public:
    bool isPal(int i, int j, string &s) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    int solve(int i, int j, string &s, vector<int> &dp) {
        if (i >= j || isPal(i, j, s)) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = 1e9;
        for (int k = i; k < j; k++) {
            if (isPal(i, k, s)) {
                ans = min(ans, 1 + solve(k + 1, j, s, dp));
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, n - 1, s, dp);
    }
};
