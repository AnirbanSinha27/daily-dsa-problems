class Solution {
    public:
        int concatenatedBinary(int n) {
            int M = 1e9 + 7;
            long result = 0;
            int digit=0;
    
            for(int i=1;i<=n;i++){
                digit = log2(i) + 1;
                result = ((result << digit)%M + i)%M;
            }
            return result;
        }
    };