class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp="";

        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp!=""){
                    words.push_back(temp);
                    temp="";
                }
                }
                else{
                    temp+=s[i];

                }
            }
            if(temp!="") words.push_back(temp);
            reverse(words.begin(),words.end());

            string ans="";
            for(int i=0;i<words.size();i++){
                ans+=words[i];
                if(i!=words.size()-1) ans+=" ";
            }
            return ans;
    }
};