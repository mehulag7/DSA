class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        long long b = 1LL * m * k;
        if (b > n) return -1;

        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int count = 0, p = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) p++;
                else p = 0;

                if (p == k) {
                    count++;
                    p = 0;
                }
            }

            if (count >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};