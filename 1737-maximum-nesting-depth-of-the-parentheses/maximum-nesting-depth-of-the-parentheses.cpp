class Solution {
public:
    int maxDepth(string s) {
        int currentdepth=0;
        int maxielement=0;

        for(char ch : s){
            if( ch=='('){
                currentdepth++;
                maxielement=max(currentdepth,maxielement);
            }
            else if(ch==')'){
                currentdepth--;
            }
            
        }
        return maxielement;
        
    }
};