class Solution {
public:
    int change(int tar, vector<int>& coins) {
        int n =coins.size();
        vector<vector<int>>dp(n+1, vector<int>(tar+1,0));
        for(int i = 0; i <= n; i++) {
    dp[i][0] = 1;
}
        for(int i=n-1;i>=0;i--){
            for(int t=1;t<=tar;t++){
                int nt =dp[i+1][t];
                int tk=0;
                if(coins[i]<=t){
                    tk=dp[i][t-coins[i]];
                }
                dp[i][t]=nt+tk;
            }
        }
        return dp[0][tar];
    }
};
