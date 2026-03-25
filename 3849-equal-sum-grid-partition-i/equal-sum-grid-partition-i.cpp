class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        if(grid.empty() || grid[0].empty()) return false;

        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;

        for(auto &row : grid){
            for(auto &val : row){
                total += val;
            }
        }

        if(total % 2 != 0) return false;

        long long target = total / 2;

        long long sum = 0;

        // horizontal
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m; j++){
                sum += grid[i][j];
            }
            if(sum == target) return true;
        }

        // vertical
        sum = 0;
        for(int j = 0; j < m - 1; j++){
            for(int i = 0; i < n; i++){
                sum += grid[i][j];
            }
            if(sum == target) return true;
        }

        return false;
    }
};