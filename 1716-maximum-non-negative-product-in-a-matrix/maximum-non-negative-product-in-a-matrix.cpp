class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<long long>> maxProd(n, vector<long long>(m));
        vector<vector<long long>> minProd(n, vector<long long>(m));
        
        maxProd[0][0] = minProd[0][0] = grid[0][0];
    
        for(int j = 1; j < m; j++){
            maxProd[0][j] = maxProd[0][j-1] * grid[0][j];
            minProd[0][j] = maxProd[0][j];
        }
        
    
        for(int i = 1; i < n; i++){
            maxProd[i][0] = maxProd[i-1][0] * grid[i][0];
            minProd[i][0] = maxProd[i][0];
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                long long a = grid[i][j] * maxProd[i-1][j];
                long long b = grid[i][j] * minProd[i-1][j];
                long long c = grid[i][j] * maxProd[i][j-1];
                long long d = grid[i][j] * minProd[i][j-1];
                
                maxProd[i][j] = max({a, b, c, d});
                minProd[i][j] = min({a, b, c, d});
            }
        }
        
        long long res = maxProd[n-1][m-1];
        if(res < 0) return -1;
        
        return res % 1000000007;
    }
};