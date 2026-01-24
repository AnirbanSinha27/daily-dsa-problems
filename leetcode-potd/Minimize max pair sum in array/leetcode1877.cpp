class Solution {
    public:
        int minPairSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int result=0;
    
            int i=0;
            int j=nums.size()-1;
    
            while(i<=j){
                int sum = nums[i] + nums[j];
                result=max(sum,result);
                i++;
                j--;
            }
            return result;
        }
    };