class Solution {
    public:
        long long maximumHappinessSum(vector<int>& happiness, int k) {
            int n=happiness.size();
            long long result=0;
            int count=0;
            priority_queue<int> pq;
    
            for(auto &el:happiness){
                pq.push(el);
            }
    
            for(int i=0;i<k;i++){
                int hap=pq.top();
                pq.pop();
                result+= max(0, hap - count);
                count++;
            }
            return result;
        }
    };