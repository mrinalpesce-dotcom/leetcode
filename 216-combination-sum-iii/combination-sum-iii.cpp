class Solution {
public:
     void cominationsum(int index, int k, int n , vector<int> &current,vector<vector<int>> &ans){
        if(k==0){
            if(n==0){
                ans.push_back(current);
            }
            return;
        }

        for(int i=index;i<=9;i++){

            if(i>n)
            break;

            current.push_back(i);
            cominationsum(i+1,k-1,n-i,current,ans);
            current.pop_back();

        }
 }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        vector<vector<int>> ans;
        cominationsum(1,k,n,current,ans);
        return ans;
        
    }
};