class Solution {
    public:
        int minDeletionSize(vector<string>& strs) {
            int n=strs.size();
            int m=strs[0].length();
    
            vector<bool> alreadySorted(n-1,false);
    
            int deletion=0;
    
            for(int col=0;col<m;col++){
                bool needDelete=false;
                for(int row=0; row<n-1;row++){
                    if(strs[row][col] > strs[row+1][col] && !alreadySorted[row]){
                        needDelete=true;
                        break;
                    } 
                }
                if(needDelete){
                    deletion++;
                    continue;
                }
                for(int row=0;row<n-1;row++){
                    if(strs[row][col] < strs[row+1][col] && !alreadySorted[row]){
                        alreadySorted[row]=true;
                    }
                }
            }
            return deletion;
        }
    };