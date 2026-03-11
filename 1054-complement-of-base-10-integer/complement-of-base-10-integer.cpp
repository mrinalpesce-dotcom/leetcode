class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;

        vector<int> ans;

        while(n != 0){
            int m = n % 2;
            n = n / 2;
            ans.push_back(m);
        }

        reverse(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == 0)
                ans[i] = 1;
            else
                ans[i] = 0;
        }

        int res = 0;

        for(int i = 0; i < ans.size(); i++){
            res = res * 2 + ans[i];
        }

        return res;
    }
};