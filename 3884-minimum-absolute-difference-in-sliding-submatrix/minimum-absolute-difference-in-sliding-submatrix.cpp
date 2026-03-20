class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for(int i = 0; i <= n - k; i++) {
            for(int j = 0; j <= m - k; j++) {

                vector<int> arr;

                // collect elements
                for(int x = i; x < i + k; x++) {
                    for(int y = j; y < j + k; y++) {
                        arr.push_back(grid[x][y]);
                    }
                }

                sort(arr.begin(), arr.end());

                int minDiff = INT_MAX;

                for(int t = 1; t < arr.size(); t++) {
                    if(arr[t] == arr[t-1]) continue; // skip duplicates
                    minDiff = min(minDiff, arr[t] - arr[t - 1]);
                }

                // 🔥 KEY FIX
                if(minDiff == INT_MAX) minDiff = 0;

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};