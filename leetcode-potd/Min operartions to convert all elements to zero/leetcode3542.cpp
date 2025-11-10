class Solution {
    public:
        int minOperations(vector<int>& nums) {
            stack<int> st;
            int op=0;
            
            for(int i=0;i<nums.size();i++){
                
                //monotonic increasing stack
                while(!st.empty() && nums[i]<st.top()){
                    st.pop();
                }
    
                if(nums[i]==0) continue;
    
                if(st.empty() || nums[i]>st.top()){
                    st.push(nums[i]);
                    op++;
                }
            }
            return op;
        }
    };