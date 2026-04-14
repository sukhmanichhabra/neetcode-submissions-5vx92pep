class Solution {
public:
    int minDistance(string w1, string w2) {
        int m =w1.length();
        int n =w2.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]= 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};
