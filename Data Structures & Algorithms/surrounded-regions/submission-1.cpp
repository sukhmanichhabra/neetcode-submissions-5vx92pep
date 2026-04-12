class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<bool>>vis(m , vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
        
                if(grid[i][0]=='O'){
                    vis[i][0]=true;
                    q.push({i,0});
                }
                 if(grid[i][n-1]=='O'){
                    vis[i][n-1]=true;
                    q.push({i,n-1});
                }
        }
         for(int i=0;i<n;i++){
        
                if(grid[0][i]=='O'){
                    vis[0][i]=true;
                    q.push({0,i});
                }
                 if(grid[m-1][i]=='O'){
                    vis[m-1][i]=true;
                    q.push({m-1,i});
                }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
auto [x,y]=q.front();
q.pop();
for(int i=0;i<4;i++){
    int nx=dx[i]+x;
    int ny=dy[i]+y;
    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='O' && !vis[nx][ny]){
        vis[nx][ny]=true;
        q.push({nx,ny});
    }
}
        }
           for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
            if(grid[i][j]=='O' && !vis[i][j]){
                grid[i][j]='X';
            }
           }
           }
    
    }
};
