class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while(n >= d){
            long long temp = d;
            long long mul = 1;

            while(n >= (temp << 1)){
                temp <<= 1;
                mul <<= 1;
            }

            n -= temp;
            ans += mul;
        }

        if((dividend > 0) ^ (divisor > 0))
            ans = -ans;

        return (int)ans;
    }
};