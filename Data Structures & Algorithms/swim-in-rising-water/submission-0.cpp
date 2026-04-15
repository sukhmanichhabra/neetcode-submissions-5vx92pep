class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int maxi = it.first;
            auto [x, y] = it.second;

            if(vis[x][y]) continue;  // ✅ avoid duplicates
            vis[x][y] = true;

            if(x == m-1 && y == n-1) return maxi;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]){
                    int newMax = max(maxi, grid[nx][ny]);  // ✅ fix
                    pq.push({newMax, {nx, ny}});
                }
            }
        }
        return -1;
    }
};