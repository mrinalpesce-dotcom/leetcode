class Solution {
public:
    void recurse(int n, vector<int>& dp){
        dp[n]=0;
        for(int i=1;i*i<=n;++i){
            if(dp[n-i*i]==-1)
                recurse(n-i*i,dp);

            if(dp[n-i*i]==0){
                dp[n]=1;
                break;
            }
        }
    }

    bool winnerSquareGame(int n){
        vector<int> dp(n+1,-1);
        dp[0]=0;
        recurse(n,dp);
        return dp[n];
    }
};