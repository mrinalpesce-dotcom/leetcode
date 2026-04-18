class Solution {
public:

    // function to reverse digits
    int reverseNum(int x){
        int rev = 0;
        while(x > 0){
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        return rev;
    }

    int mirrorDistance(int n) {
        int rev = reverseNum(n);   // reverse the input number
        int ans = abs(n - rev);    // find absolute difference
        return ans;                // return inside function
    }
};