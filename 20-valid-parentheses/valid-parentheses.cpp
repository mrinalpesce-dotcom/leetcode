class Solution {
public:
    bool isValid(string s) {
        // intialized the stack;
        stack<char> q;

        for(char ch: s){

            if(ch=='(' || ch=='{'|| ch=='['){
            q.push(ch);
            continue;
            }
        
        if(q.empty())
            return false;
        


        char topbra=q.top();

        if(ch==')' && topbra!='(')
            return false;
        
          if(ch=='}' && topbra!='{')
            return false;
        
          if(ch==']' && topbra!='[')
            return false;
        
        q.pop();
        }
       
       return q.empty();
    }
   
    
};