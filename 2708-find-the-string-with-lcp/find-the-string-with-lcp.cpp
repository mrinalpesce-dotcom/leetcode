class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '?');
        
        // Step 1: diagonal check
        for(int i=0;i<n;i++){
            if(lcp[i][i] != n-i) return "";
        }
        
        // Step 2: build lexicographically smallest string
        char ch = 'a';
        
        for(int i=0;i<n;i++){
            if(s[i] == '?'){
                if(ch > 'z') return ""; // more than 26 groups
                
                for(int j=i;j<n;j++){
                    if(lcp[i][j] > 0){
                        s[j] = ch;
                    }
                }
                ch++;
            }
        }
        
        // Step 3: build LCP from constructed string
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i] == s[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
            }
        }
        
        // Step 4: compare matrices
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] != lcp[i][j]) return "";
            }
        }
        
        return s;
    }
};