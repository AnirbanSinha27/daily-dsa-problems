class Solution {
public:
    static const int MOD = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,long long> left_map;
        unordered_map<int,long long> right_map;

        for (int x : nums) {
            right_map[x]++;
        }

        long long triplet = 0;

        for (int i = 0; i < n; ++i) {
            right_map[nums[i]]--;
            if (right_map[nums[i]] == 0) {
                right_map.erase(nums[i]);
            }

            long long mid = nums[i];
            long long target = 2 * mid;

            auto itL = left_map.find((int)target);
            auto itR = right_map.find((int)target);
            if (itL != left_map.end() && itR != right_map.end()) {
                triplet = (triplet + itL->second * itR->second) % MOD;
            }
            
            left_map[nums[i]]++;
        }

        return (int)triplet;
    }
};
