class Solution {
    public:
    
        int countSumDivisors(int n){
            int sum=0;
            int divisor=0;
    
            for(int fact=1;fact<=sqrt(n);fact++){
                if(n%fact == 0){
                    int other = n/fact;
                    if(other == fact){
                        divisor++;
                        sum+=fact;
                    }
                    else{
                        divisor+=2;
                        sum+= fact + other;
                    }
                }
    
                if(divisor > 4) break;
            }
            if(divisor == 4) return sum;
            else return 0;
        }
    
        int sumFourDivisors(vector<int>& nums) {
            int result=0;
    
            for(int num: nums){
                result+= countSumDivisors(num);
            }
    
            return result;
        }
    };