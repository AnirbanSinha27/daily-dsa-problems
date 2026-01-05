class Solution {
    public:
        long long maxMatrixSum(vector<vector<int>>& matrix) {
            long long sum=0;
            int negativeCount=0;
            int smallestAbs=INT_MAX;
            int n=matrix.size();
    
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    sum+= abs(matrix[i][j]);
                    if(matrix[i][j]<0) negativeCount++;
                    smallestAbs= min(smallestAbs,abs(matrix[i][j]));
                }
            }
    
            if(negativeCount % 2==0) return sum;
            else return sum - 2*smallestAbs ;
        }
    };