class Solution {
public:
    vector<string> ans;

    void GenerateString(int n, string curr) {
        if(curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(curr.empty() || curr.back() != ch) {
                GenerateString(n, curr + ch);
            }
        }
    }

    string getHappyString(int n, int k) {
        GenerateString(n, "");

        if(k > ans.size()) {
            return "";
        }

        return ans[k-1];
    }
};