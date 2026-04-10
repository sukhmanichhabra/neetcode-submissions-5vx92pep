class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dis(n+1, 1e9);
        
        // Build graph
        for(auto &t : times){
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }
        
        dis[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(wt > dis[node]) continue;
            
            for(auto &[it, w] : adj[node]){
                if(dis[node] + w < dis[it]){
                    dis[it] = dis[node] + w;
                    pq.push({dis[it], it});
                }
            }
        }
        
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dis[i] == 1e9) return -1;
            maxi = max(maxi, dis[i]);
        }
        
        return maxi;
    }
};