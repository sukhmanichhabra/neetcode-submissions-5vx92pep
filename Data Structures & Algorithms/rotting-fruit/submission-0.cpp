class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) cnt++;
                else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if(q.empty() && cnt > 0) return -1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int time = 0;

        while(!q.empty()){
            int sz = q.size();
            bool rotted = false; // 🔑 track if anything rotted this round

            for(int i = 0; i < sz; i++){
                auto [x, y] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        cnt--;
                        q.push({nx, ny});
                        rotted = true;
                    }
                }
            }

            if(rotted) time++; // only increment when spread happens
        }

        return (cnt == 0) ? time : -1;
    }
};