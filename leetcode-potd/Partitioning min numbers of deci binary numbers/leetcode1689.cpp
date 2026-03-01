class Solution {
    public:
        int minPartitions(string n) {
            char maxElement = *max_element(begin(n),end(n));
    
            return maxElement - '0';
        }
    };