class Solution {
    public:
    
        int M = 1e9 + 7;
    
        int solve(int onesLeft, int zeroesLeft, int limit, int lastWasOne,vector<vector<vector<int>>> &dp){
            if(onesLeft == 0 && zeroesLeft == 0) return 1;
    
            if(dp[onesLeft][zeroesLeft][lastWasOne] != -1) return dp[onesLeft][zeroesLeft][lastWasOne];
    
            int result = 0;
    
            if(lastWasOne == true){
                for(int i=1; i<=min(limit, zeroesLeft);i++){
                    result = (result + solve(onesLeft, zeroesLeft - i,limit,false,dp)) % M;
                }
            }
            else{
                for(int i=1;i<=min(limit, onesLeft);i++){
                    result = (result + solve(onesLeft - i,zeroesLeft,limit,true,dp)) % M;
                }
            }
            return dp[onesLeft][zeroesLeft][lastWasOne] = result;
        }
    
        int numberOfStableArrays(int zero, int one, int limit) {
    
            vector<vector<vector<int>>> dp(
        one + 1,
        vector<vector<int>>(zero + 1, vector<int>(2, -1))
    );
    
            int startWithOne = solve(one,zero,limit,false,dp);
            int startWithZero = solve(one,zero,limit,true,dp);
    
            return (startWithOne + startWithZero) % M;
        }
    };