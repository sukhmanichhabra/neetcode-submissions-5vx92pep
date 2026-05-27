class Solution {
public:
   
    bool canReach(string s, int mi, int ma) {
        int n = s.size();
     queue<int>q;
     vector<bool>vis(n,false);
     q.push(0);
     vis[0]=true;
     while(!q.empty()){
        auto ind=q.front();
        if(ind==n-1)return true;
        q.pop();
        int st=ind+mi;
        int end =min(ind+ma,n-1);
        for(int i=st;i<=end;i++){
            if(s[i]=='0'&& !vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
     }
     return false;
    }
};