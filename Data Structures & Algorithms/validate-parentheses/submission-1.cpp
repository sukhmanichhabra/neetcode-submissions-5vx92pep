class Solution {
public:
    bool isValid(string s) {
       if(s.empty())return true;
        stack<char>st;
        for(auto it:s){
            if(it=='(' || it=='[' || it=='{'){
st.push(it);
            }
else if(it==')'){
    if(!st.empty() && st.top()=='('){
st.pop();
    }
    else{
        return false;
    }
}
else if(it=='}'){
    if(!st.empty() && st.top()=='{'){
st.pop();
    }
    else{
        return false;
    }
}
else if(it==']'){
    if(!st.empty() && st.top()=='['){
st.pop();
    }
    else{
        return false;
    }
}

        }
        return st.empty();
    }
};
