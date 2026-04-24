class MinStack {
public:
stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(st.empty())return -1;
        stack<int>t;
        int mini =INT_MAX;
        while(!st.empty()){
mini=min(st.top(),mini);
t.push(st.top());
st.pop();
        }
        while(!t.empty()){
            st.push(t.top());
            t.pop();
        }
        return mini;
    }
};
