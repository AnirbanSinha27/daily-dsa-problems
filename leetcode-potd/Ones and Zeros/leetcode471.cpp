class Solution {
    public:
    
        int solve(int i,int m,int n,vector<pair<int,int>> &count,vector<vector<vector<int>>> &dp){
            if(i >= count.size() || (m==0 && n==0)){
                return 0;
            }
    
            if(dp[i][m][n]!=-1) return dp[i][m][n];
    
            int notTake = solve(i+1,m,n,count,dp);
            int take= 0;
            if(count[i].first <= m && count[i].second <= n){
                take = 1 + solve(i+1, m - count[i].first, n - count[i].second,count,dp);
            }
            return dp[i][m][n] = max(take,notTake);
        }
    
        int findMaxForm(vector<string>& strs, int m, int n) {
            int N=strs.size();
            vector<pair<int,int>> count(N);
            vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
    
            for(int i=0;i<N;i++){
                int zero=0;
                int one=0;
                for(auto &el: strs[i]){
                    if(el=='0') zero++;
                    else one++;
                }
                count[i]={zero,one};
            }
    
            for(int i=N-1;i>=0;i--){
                for(int j=0;j<=m;j++){
                    for(int k=0;k<=n;k++){
                        int notTake = dp[i+1][j][k];
                        int take= 0;
                        if(count[i].first <= j && count[i].second <= k){
                            take = 1 + dp[i+1][j - count[i].first][k - count[i].second];
                        }
                        dp[i][j][k] = max(take,notTake);
                    }
                }
            }
    
            return dp[0][m][n];
        }
    };