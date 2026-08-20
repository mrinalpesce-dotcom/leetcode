class Solution {
public:

    // Check whether we can place a queen at matrix[row][col]
    bool isSafe(vector<vector<int>>& matrix, int row, int col, int n) {

        // Check same column
        for(int i = 0; i < row; i++) {
            if(matrix[i][col] == 1) {
                return false;
            }
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while(i >= 0 && j >= 0) {
            if(matrix[i][j] == 1) {
                return false;
            }
            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while(i >= 0 && j < n) {
            if(matrix[i][j] == 1) {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }


    void dfs(int row, int n,
             vector<vector<int>>& matrix,
             vector<vector<string>>& ans) {

        // All queens have been placed
        if(row == n) {

            vector<string> board;

            for(int i = 0; i < n; i++) {

                string current = "";

                for(int j = 0; j < n; j++) {

                    if(matrix[i][j] == 1) {
                        current += 'Q';
                    }
                    else {
                        current += '.';
                    }
                }

                board.push_back(current);
            }

            ans.push_back(board);
            return;
        }


        // Try every column in current row
        for(int col = 0; col < n; col++) {

            // Check whether queen can be placed
            if(isSafe(matrix, row, col, n)) {

                // Place queen
                matrix[row][col] = 1;

                // Move to next row
                dfs(row + 1, n, matrix, ans);

                // Backtrack
                matrix[row][col] = 0;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        // Create n x n matrix
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        vector<vector<string>> ans;

        // Start from row 0
        dfs(0, n, matrix, ans);

        return ans;
    }
};