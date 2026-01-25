class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long ans = 0;
        int sign = 1;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Overflow check BEFORE update
            if (ans > (LLONG_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        ans *= sign;

        // 5. Clamp to int range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};
