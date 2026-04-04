class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        // ⭐ Edge case
        if(rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        // Build matrix row-wise
        vector<vector<char>> mat(rows, vector<char>(cols));
        int index = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                mat[i][j] = encodedText[index++];
            }
        }

        // Read diagonally
        string ans = "";
        for(int startCol = 0; startCol < cols; startCol++){
            int i = 0, j = startCol;
            while(i < rows && j < cols){
                ans += mat[i][j];
                i++;
                j++;
            }
        }

        // Remove trailing spaces
        while(!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};