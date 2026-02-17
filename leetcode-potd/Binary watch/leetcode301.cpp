class Solution {
    public:
        vector<string> readBinaryWatch(int turnedOn) {
            vector<string> result;
            for(int i=0;i<12;i++){
                for(int j=0;j<60;j++){
                    if(__builtin_popcount(i)+ __builtin_popcount(j)==turnedOn){
                        string hour = to_string(i);
                        string minute = (j<10 ? "0":"") + to_string(j);
                        result.push_back(hour + ":" + minute);
                    }
                }
            }
            return result;
        }
    };