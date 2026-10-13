class MinStack {
public:
        vector<pair<int , int>>s;
    MinStack() {

        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push_back({val ,val});
        }
        else{
        int mini=min(s.back().second,val);
        s.push_back({val,mini});
        }

        
    }
    
    void pop() {
        s.pop_back();
        
    }
    
    int top() {
        return s.back().first;
        
    }
    
    int getMin() {
        return s.back().second;
        
    
}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */