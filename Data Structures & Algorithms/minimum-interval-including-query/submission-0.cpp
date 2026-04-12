class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& inte, vector<int>& q) {
        vector<int>mp(10001,1e9);
        for(auto it:inte){
            int st =it[0];
            int end=it[1];
            int l=end-st+1;
            for(int i=st;i<=end;i++){
                mp[i]=min(mp[i],l);
            }
        }
        int n =q.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
int val =mp[q[i]];
if(val!=1e9)ans[i]=val;
        }
        return ans;
    }
};
