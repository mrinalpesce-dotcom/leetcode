class Solution {
public:

void combinationsum(int index, string current,vector<string> &ans , string digits ){

    if(index==digits.length()){
        ans.push_back(current);
        return;
    }
    vector<string> map{
        " "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    int digit = digits[index]-'0';

    for(char ch: map[digit]){
        current.push_back(ch);
        combinationsum(index+1,current,ans ,digits);

        current.pop_back();
    }
        
        }

    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }

        combinationsum(0,"", ans ,digits);
        return ans;

        
    }
};