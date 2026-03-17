class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Build heights (histogram)
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        int maxArea = 0;

        // Step 2: Process each row
        for(int i = 0; i < n; i++){
            vector<int> row = matrix[i];

            // Step 3: Sort in descending order
            sort(row.begin(), row.end(), greater<int>());

            // Step 4: Calculate max area
            for(int j = 0; j < m; j++){
                int height = row[j];
                int width = j + 1;
                maxArea = max(maxArea, height * width);
            }
        }

        return maxArea;
    }
};