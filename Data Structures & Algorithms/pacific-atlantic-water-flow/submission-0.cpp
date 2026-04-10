class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(vector<vector<int>>& h, vector<vector<bool>>& ocean, int x, int y, int m, int n) {
        ocean[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                !ocean[nx][ny] &&
                h[nx][ny] >= h[x][y]) {

                dfs(h, ocean, nx, ny, m, n);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();

        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));

        // Pacific (top row + left column)
        for (int j = 0; j < n; j++) dfs(h, p, 0, j, m, n);
        for (int i = 0; i < m; i++) dfs(h, p, i, 0, m, n);

        // Atlantic (bottom row + right column)
        for (int j = 0; j < n; j++) dfs(h, a, m - 1, j, m, n);
        for (int i = 0; i < m; i++) dfs(h, a, i, n - 1, m, n);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};