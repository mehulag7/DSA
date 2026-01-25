class Solution {
public:
    static const long long M = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0) return 1;
        long long half = power(x, n / 2);
        half = (half * half) % M;
        if (n % 2) {
            half = (half * x) % M;
        }
        return half;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;  // positions for even digits
        long long odd = n / 2;         // positions for odd digits

        long long x = power(5, even);
        long long y = power(4, odd);

        return (x * y) % M;
    }
};
