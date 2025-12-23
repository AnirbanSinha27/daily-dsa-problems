class Solution {
    public:
    
        int binarySearch(vector<vector<int>>& events, int endTime,int n){
            int low=0;
            int high= n-1;
            int result=n;
    
            while(low<=high){
                int mid= low + (high-low)/2;
    
                if(events[mid][0] > endTime){
                    result = mid;
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return result;
        }
    
        int solve(int i,int count,vector<vector<int>>& events,int n,vector<vector<int>> &dp){
            if(count==2 || i>=n) return 0;
    
            if(dp[i][count]!=-1) return dp[i][count];
    
            int notTake = solve(i+1,count,events,n,dp);
            int nextIndex = binarySearch(events,events[i][1],n);
    
            int take= events[i][2] + solve(nextIndex,count+1,events,n,dp);
    
            return dp[i][count] = max(take,notTake);
        }
    
        int maxTwoEvents(vector<vector<int>>& events) {
            int n=events.size();
            sort(events.begin(),events.end());
            int count=0;
    
            vector<vector<int>> dp(n+1,vector<int>(3,-1));
    
            return solve(0,count,events,n,dp);
        }
    };