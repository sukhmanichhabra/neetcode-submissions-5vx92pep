class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int>mp;
        for(auto it:intervals){
            mp[it[0]]++;
            mp[it[1]]--;
        }
      
        int cnt =0;
        int st;
        int end;
        vector<vector<int>>ans;
        for(auto it:mp){
if(cnt==0)st=it.first;
cnt+=it.second;
if(cnt==0){
    end =it.first;
    ans.push_back({st,end});
}
        }
        return ans;
    }
};
