//TOP DOWN APPROACH

class Solution {
    public:
    
        long long solve(int i, int CASE,vector<int>& prices, int k,vector<vector<vector<long long>>> &dp){
            if(i>=prices.size()){
                if(CASE == 0) return 0;
                else return INT_MIN;
            }
    
            if(dp[i][k][CASE] != INT_MIN) return dp[i][k][CASE];
    
            long long notTake = solve(i+1, CASE, prices, k,dp);
            long long take=INT_MIN;
    
            if(k>0){
                if(CASE==1){
                    take = prices[i] + solve(i+1,0,prices,k-1,dp);
                }
                else if(CASE ==2){
                    take = -prices[i] + solve(i+1,0,prices,k-1,dp);
                }
                else{
                    take = max(
                        -prices[i] + solve(i+1,1,prices,k,dp),
                        prices[i] + solve(i+1,2,prices,k,dp)
                    );
                }
            }
            return dp[i][k][CASE] =max(take,notTake);
        }
    
        long long maximumProfit(vector<int>& prices, int k) {
    
            int n=prices.size();
    
            vector<vector<vector<long long>>> dp(
                n+1,
                vector<vector<long long>> (n/2+1,
                vector<long long> (3,INT_MIN))
            );
    
            return solve(0,0,prices,k,dp);
        }
    };