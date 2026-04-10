class Solution {
public:
bool is(int l, int r,string p){
    while(l<r){
        if(p[l]!=p[r])return false;
        l++;
        r--;
    }
    return true;
}

void solve(vector<string>&ans, vector<vector<string>>&temp,int ind,string s,int n ){
    if(ind==n){
        temp.push_back(ans);
    }
    for(int i=ind;i<n;i++){
        if(is(0, i-ind, s.substr(ind, i-ind+1))){
            ans.push_back( s.substr(ind, i-ind+1));
            solve(ans,temp,i+1,s,n);
            ans.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>temp;
vector<string>ans;
int n =s.size();
solve(ans,temp,0,s,n);
return temp;
    }
};
