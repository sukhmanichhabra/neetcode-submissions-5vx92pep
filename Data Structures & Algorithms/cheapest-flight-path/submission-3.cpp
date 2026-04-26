class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // cost , stops used , node
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>> > pq;

        pq.push({0, {0, src}});

        // dist[node][stops]
        vector<vector<int>> dis(n, vector<int>(k + 2, 1e9));
        dis[src][0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int d = cur.first;
            int step = cur.second.first;
            int node = cur.second.second;

            if (node == dst) return d;

            if (step > k) continue;

            for (auto &[nextNode, wt] : adj[node]) {
                if (d + wt < dis[nextNode][step + 1]) {
                    dis[nextNode][step + 1] = d + wt;
                    pq.push({d + wt, {step + 1, nextNode}});
                }
            }
        }

        return -1;
    }
};