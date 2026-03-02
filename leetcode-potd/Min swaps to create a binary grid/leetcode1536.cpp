class Solution {
    public:
        int minSwaps(vector<vector<int>>& grid) {
            int n=grid.size();
            int result = 0;
            vector<int> endZeroes(n,0);
    
            for(int i=0;i<n;i++){
                int j=n-1;
                int zeroes=0;
                while(j>=0){
                    if(grid[i][j]==0) zeroes++;
                    else break;
                    j--;
                }
                endZeroes[i]=zeroes;
            }
    
            for(int i=0;i<n;i++){
                int need = n - i - 1;
                int j=i;
    
                while(j<n && endZeroes[j] < need){
                    j++;
                }
    
                if(j == n) return -1;
    
                result+=j - i;
    
                while(j > i){
                    swap(endZeroes[j],endZeroes[j-1]);
                    j--;
                }
            }
            return result;
        }
    };