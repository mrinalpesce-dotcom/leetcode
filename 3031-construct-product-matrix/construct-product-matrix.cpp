class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n * m;

        int MOD = 12345;

        vector<long long> ans(size);

        // Step 1: Prefix
        ans[0] = 1;
        for(int k = 1; k < size; k++){
            int i = (k-1) / m;
            int j = (k-1) % m;

            ans[k] = (ans[k-1] * grid[i][j]) % MOD;
        }

        // Step 2: Suffix
        long long suffix = 1;
        for(int k = size - 1; k >= 0; k--){
            int i = k / m;
            int j = k % m;

            ans[k] = (ans[k] * suffix) % MOD;
            suffix = (suffix * grid[i][j]) % MOD;
        }

        vector<vector<int>> result(n, vector<int>(m));
        int k = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = ans[k++];
            }
        }

        return result;
    }
};