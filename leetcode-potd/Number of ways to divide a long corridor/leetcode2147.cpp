class Solution {
    public:
    
        int MOD= 1e9+7;
    
        int numberOfWays(string corridor) {
            int n=corridor.length();
            vector<int> seatPosition;
    
            for(int i=0;i<n;i++){
                if(corridor[i]=='S') seatPosition.push_back(i);
            }
            if(seatPosition.size() %2 !=0 || seatPosition.size()==0) return 0;
    
            int prevSeat=seatPosition[1];
            long long res=1;
    
            for(int i=2;i<seatPosition.size();i+=2){
                int currSeat=seatPosition[i];
                res = (res * (currSeat - prevSeat)) % MOD;
                prevSeat=seatPosition[i+1];
            }
            return (int)res;
        }
    };