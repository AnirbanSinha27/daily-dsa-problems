class Solution {
    public:
        vector<int> getNSR(vector<int>& height) {
            stack<int> st;
            int n = height.size();
            vector<int> NSR(n);
    
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                NSR[i] = st.empty() ? n : st.top();
                st.push(i);
            }
            return NSR;
        }
    
        vector<int> getNSL(vector<int>& height) {
            stack<int> st;
            int n = height.size();
            vector<int> NSL(n);
    
            for (int i = 0; i < n; i++) {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                NSL[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            return NSL;
        }
    
        int findMaxArea(vector<int>& height) {
            vector<int> NSR = getNSR(height);
            vector<int> NSL = getNSL(height);
    
            int n = height.size();
            int maxArea = 0;
    
            for (int i = 0; i < n; i++) {
                int width = NSR[i] - NSL[i] - 1;
                int area = width * height[i];
                maxArea = max(maxArea, area);
            }
            return maxArea;
        }
    
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty() || matrix[0].empty()) return 0;
    
            int row = matrix.size();
            int col = matrix[0].size();
            vector<int> height(col, 0);
    
            int maxArea = 0;
    
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (matrix[i][j] == '0') height[j] = 0;
                    else height[j] += 1;
                }
                maxArea = max(maxArea, findMaxArea(height));
            }
    
            return maxArea;
        }
    };
    