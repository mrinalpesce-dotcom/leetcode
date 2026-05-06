class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int m = box.size();
        int n = box[0].size();

        // Step 1: simulate gravity (fall right)
        for(int i = 0; i < m; i++)
        {
            int emptyPos = n - 1;
            
            for(int j = n - 1; j >= 0; j--)
            {
                if(box[i][j] == '*')
                {
                    emptyPos = j - 1;
                }
                else if(box[i][j] == '#')
                {
                    swap(box[i][j], box[i][emptyPos]);
                    emptyPos--;
                }
            }
        }

        // Step 2: rotate matrix
        vector<vector<char>> ans(n, vector<char>(m));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans[j][m - 1 - i] = box[i][j];
            }
        }

        return ans;
    }
};