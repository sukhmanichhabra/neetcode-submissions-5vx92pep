class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>ind(n,0);
        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;

        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        if(q.empty())return false;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
               
            }
        }
        return cnt ==n;
    }
};
