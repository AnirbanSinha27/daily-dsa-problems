class Solution {
    public:
    
        int MOD= 1e9 + 7;
        string states[12]={"RYR","RYG","RGR","RGY","YRY","YRG","YGR","YGY","GRY","GRG","GYR","GYG"};
    
        int solve(int n, int prev , vector<vector<int>>& dp){
    
            if(n<=0) return 1;
    
            if(dp[n][prev]!= -1) return dp[n][prev];
    
            string lastState= states[prev];
            int result=0;
    
            for(int curr=0;curr<12;curr++){
                if(curr == prev) continue;
    
                string currState = states[curr];
                bool conflict = false;
                for(int col=0;col<3;col++){
                    if(currState[col]==lastState[col]){
                        conflict = true;
                        break;
                    }
                }
                if(!conflict){
                    result = (result + solve(n-1,curr,dp)) % MOD;
                }
            }
            return dp[n][prev] = result;
        }
    
        int numOfWays(int n) {
            int result=0;
    
            vector<vector<int>> dp(n, vector<int> (12,-1));
    
            for(int i=0;i<12;i++){
                result = (result + solve(n-1,i,dp)) % MOD;
            }
    
            return result;
        }
    };