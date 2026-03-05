class Solution {
    public:
        int minOperations(string s) {
            int n=s.length();
            int zeroStart = 0; //010101...
    
            for(int i=0;i<n;i++){
                if(i%2==0){
                    if(s[i]=='1'){
                        zeroStart++;
                    }
                }
                else{
                    if(s[i]=='0'){
                        zeroStart++;
                    }
                }
            }
            int oneStart = n - zeroStart;
            return min(oneStart,zeroStart);
        }
    };