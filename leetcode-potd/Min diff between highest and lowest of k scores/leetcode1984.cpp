class Solution {
    public:
        int minimumDifference(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            int i=0;
            int j=k-1;
            int result=INT_MAX;
    
            while(j<=nums.size()-1){
                int mini = nums[j] - nums[i];
                result = min(result,mini);
                i++;
                j++;
            }
            return result;
        }
    };