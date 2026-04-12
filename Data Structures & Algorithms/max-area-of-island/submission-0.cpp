class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    int area = 0;   // 🔥 track this island
                    queue<pair<int,int>> q;

                    q.push({i, j});
                    grid[i][j] = 0;

                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        area++;  // 🔥 count each cell

                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }

                    maxArea = max(maxArea, area);  // 🔥 update answer
                }
            }
        }

        return maxArea;
    }
};