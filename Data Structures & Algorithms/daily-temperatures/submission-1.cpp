class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        stack<int>st;
        int n =tem.size();
        vector<int>ans(n,0);
        if(n==0 || n==1)return ans;
        for(int i=n-1;i>=0;i--){
while(!st.empty()&& tem[st.top()]<=tem[i]){
    st.pop();
}
if(!st.empty())ans[i]=st.top()-i;
st.push(i);
        }
        return ans;
    }
};
