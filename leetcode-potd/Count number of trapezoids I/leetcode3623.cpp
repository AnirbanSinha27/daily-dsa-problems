class Solution {
    public:
        int M= 1e9 + 7;
        int countTrapezoids(vector<vector<int>>& points) {
            unordered_map<int,int> mpp;
            
            for(auto &el: points){
                int y=el[1];
                mpp[y]++;
            }
    
            long long result=0;
            long long prevSum=0;
    
            for(auto &el: mpp){
                long long count = el.second;
                long long horizontalLines = count * (count-1)/2;
    
                result += horizontalLines * prevSum;
                prevSum += horizontalLines;
            }
    
            return (int) (result % M);
        }
    };