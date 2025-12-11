class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            // maps:
            // y -> {minX on this row, maxX on this row}
            // x -> {minY on this column, maxY on this column}
            unordered_map<int, pair<int,int>> yX;
            unordered_map<int, pair<int,int>> xY;
    
            // initialize maps with extreme values
            for (auto &b : buildings) {
                int x = b[0];
                int y = b[1];
    
                if (!yX.count(y)) yX[y] = {INT_MAX, INT_MIN};
                if (!xY.count(x)) xY[x] = {INT_MAX, INT_MIN};
    
                yX[y].first  = min(yX[y].first, x);
                yX[y].second = max(yX[y].second, x);
    
                xY[x].first  = min(xY[x].first, y);
                xY[x].second = max(xY[x].second, y);
            }
    
            int result = 0;
            for (auto &b : buildings) {
                int x = b[0];
                int y = b[1];
    
                // building is covered iff its x is strictly between minX and maxX on row y
                // and its y is strictly between minY and maxY on column x
                auto &row = yX[y];
                auto &col = xY[x];
    
                if (x > row.first && x < row.second && y > col.first && y < col.second) {
                    result++;
                }
            }
            return result;
        }
    };
    