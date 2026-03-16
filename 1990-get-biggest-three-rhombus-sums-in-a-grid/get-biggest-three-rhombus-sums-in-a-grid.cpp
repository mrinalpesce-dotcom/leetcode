class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> st;   // store distinct rhombus sums
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                // size = 0 (single cell)
                st.insert(grid[i][j]);
                
                int maxSize = min({i, j, m-1-i, n-1-j});
                
                for(int k = 1; k <= maxSize; k++){
                    
                    int sum = 0;
                    
                    // top -> right
                    for(int d = 0; d < k; d++)
                        sum += grid[i-k+d][j+d];
                    
                    // right -> bottom
                    for(int d = 0; d < k; d++)
                        sum += grid[i+d][j+k-d];
                    
                    // bottom -> left
                    for(int d = 0; d < k; d++)
                        sum += grid[i+k-d][j-d];
                    
                    // left -> top
                    for(int d = 0; d < k; d++)
                        sum += grid[i-d][j-k+d];
                    
                    st.insert(sum);
                }
            }
        }
        
        vector<int> ans;
        
        // take largest 3
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++){
            ans.push_back(*it);
        }
        
        return ans;
    }
};