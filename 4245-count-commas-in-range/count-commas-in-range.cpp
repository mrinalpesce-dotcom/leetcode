class Solution {
public:
    long long  countCommas(long n) {
        long long ans=0;

        if(n>=1000){
            ans+=n-1000+1;
        }
        if(n>=1000000){
            ans+=2*(n-1000000+1);
        }
        if(n>=1000000000){
            ans+=3*(n-1000000000+1);
        }
        return ans;
        
    }
};