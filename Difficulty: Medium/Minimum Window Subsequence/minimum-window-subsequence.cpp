class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX, start = -1;

        int i = 0;
        while (i < n) {
            int j = i, k = 0;

            // forward match
            while (j < n && k < m) {
                if (s1[j] == s2[k]) k++;
                j++;
            }

            if (k < m) break;  // no more subsequence possible

            // backward shrink
            int end = j - 1;
            k = m - 1;
            while (i <= end) {
                if (s1[end] == s2[k]) k--;
                if (k < 0) break;
                end--;
            }

            if (j - end < minLen) {
                minLen = j - end;
                start = end;
            }

            i = end + 1;  // move start forward
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
