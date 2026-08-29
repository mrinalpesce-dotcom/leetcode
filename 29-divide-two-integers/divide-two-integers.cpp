#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Check whether answer should be positive
        bool positive = (dividend < 0) == (divisor < 0);

        // Convert to long long and make positive
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long ans = 0;

        // Try powers of 2 from large to small
        for (int i = 31; i >= 0; i--) {

            // Check if divisor * 2^i can fit into dividend
            if ((d << i) <= n) {

                // Add 2^i to quotient
                ans += (1LL << i);

                // Remove this amount from dividend
                n -= (d << i);
            }
        }

        // Apply sign
        if (!positive)
            ans = -ans;

        return (int)ans;
    }
};


