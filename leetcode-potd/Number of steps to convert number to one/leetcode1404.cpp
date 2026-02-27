class Solution {
    public:
        int numSteps(string s) {
            int n=s.length();
            int operations=0;
            int carry=0;
    
            for(int i=n-1;i>=1;i--){
                if((s[i]- '0' + carry)%2 == 1){
                    operations+=2;
                    carry=1;
                }
                else{
                    operations+=1;
                }
            }
            return operations + carry;
        }
    };