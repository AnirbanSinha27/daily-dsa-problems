class Solution {
    public:
        int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
            int n=apple.size();
            int m=capacity.size();
            int appleCount=0;
            int result=0;
    
            sort(capacity.begin(),capacity.end(),greater<int>());
    
            for(int i=0;i<n;i++){
                appleCount+=apple[i];
            }
    
            for(int i=0;i<m;i++){
                appleCount = max(appleCount-capacity[i],0);
                result++;
                if(appleCount==0) break;
            }
            return result;
        }
    };