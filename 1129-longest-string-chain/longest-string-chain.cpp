class Solution {
public:
    bool isPredecessor(string &a, string &b) {
        if (b.size() != a.size() + 1) return false;

        int i = 0, j = 0;
        bool skipped = false;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string &a, string &b) {
                 return a.size() < b.size();
             });

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
