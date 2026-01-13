class Solution {
    public:
    
        bool check(double totArea, double mid, vector<vector<int>>& squares){
            double botArea =0.00000;
    
            for(auto &square:squares){
                double y = square[1];
                double l = square[2];
    
                double botY = y;
                double topY = y+l;
    
                if(mid >= topY){
                    botArea += (l*l);
                }
                else if(mid>= botY){
                    botArea += ((mid-botY) * l);
                }
            }
            return (botArea >=totArea/2.0);
        }
    
        double separateSquares(vector<vector<int>>& squares) {
            double totArea = 0.00000;
            double high = INT_MIN;
            double low = INT_MAX;
    
            for(auto &square: squares){
                double x = square[0];
                double y = square[1];
                double l = square[2];
    
                totArea+= (l*l);
                high = max(high, y+l);
                low = min(low,y);
            }
    
            double result = 0.00000;
    
            while(high - low > 1e-5){
                double mid = low + (high-low)/2.0;
                result = mid;
    
                if(check(totArea,mid,squares)){
                    high = mid;
                }
                else{
                    low = mid;
                }
            }
            return result;
        }
    };