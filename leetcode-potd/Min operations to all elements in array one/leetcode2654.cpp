class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n=nums.size();
            int oneCount=0;
    
            for(int i=0;i<n;i++){
                if(nums[i]==1) oneCount++;
            }
    
            if(oneCount > 0) return (n-oneCount);
    
            int op=INT_MAX;
            for(int i=0;i<n-1;i++){
                int GCD=nums[i];
                for(int j=i+1;j<n;j++){
                    GCD=gcd(GCD,nums[j]);
                    if(GCD==1){
                        op=min(op, j-i);
                        break;
                    }
                }
            }
            if(op==INT_MAX) return -1;
            return (op + (n-1));
        }
    };