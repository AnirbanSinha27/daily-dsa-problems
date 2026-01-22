class Solution {
    public:
    
        int minSum(vector<int>& nums){
            int sum = INT_MAX;
            int index = -1;
    
            for(int i=0;i<nums.size()-1;i++){
                int minSum = nums[i]+nums[i+1];
                if(minSum < sum){
                    sum = minSum;
                    index = i;
                };
            }
            return index;
        }
    
        int minimumPairRemoval(vector<int>& nums) {
            int count=0;
    
            while(!is_sorted(nums.begin(),nums.end())){
                int index = minSum(nums);
                nums[index] = nums[index] + nums[index+1];
                nums.erase(nums.begin() + index + 1);
                count++;
            }
            return count;
        }
    };