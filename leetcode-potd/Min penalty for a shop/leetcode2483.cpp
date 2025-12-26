class Solution {
    public:
        int bestClosingTime(string customers) {
            int n=customers.length();
    
            int penalty= count(begin(customers),end(customers),'Y');
            int minPenalty=penalty;
            int minHour = 0;
    
            for(int i=0;i<n;i++){
                if(customers[i]=='Y') penalty--;
                else penalty++;
    
                if(penalty<minPenalty){
                    minPenalty=penalty;
                    minHour = i+1;
                } 
            }
            return minHour;
        }
    };