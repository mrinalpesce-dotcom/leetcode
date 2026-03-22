class Solution {
public:
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        return mat==target;
    }
    void rotate(vector<vector<int>>& mat){
        int n=mat.size();

        vector<vector<int>>temp(n, vector<int>(n));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[j][n-1-i]=mat[i][j];
                }
            }
            mat=temp;
        }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            if(isEqual(mat,target)) return true;
            rotate(mat);
        }
        return false;

        
    }
};