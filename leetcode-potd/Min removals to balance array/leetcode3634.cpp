class Solution {
    public:
        int minRemoval(vector<int>& nums, int k) {
            int i=0;
            int j=0;
            int n=nums.size();
            sort(nums.begin(),nums.end());
            int result = 1;
            int maxi = nums[0];
            int mini = nums[0];
    
            while(j<n){
                maxi = nums[j];
                mini = nums[i];
                while(i<j && maxi > (long long) k * mini){
                    i++;
                    mini=nums[i];
                }
                result = max(result, j - i + 1);
                j++;
            }
            return n - result;
        }
    };