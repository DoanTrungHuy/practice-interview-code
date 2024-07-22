class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> us(nums.begin(), nums.end());
        unordered_map<int, long long> cnt;
        
        for (int x : us) {
            cnt[__builtin_popcount(x)]++;
        }
        
        long long ans = 0;
        
        for (auto [b1, c1] : cnt) {
            for (auto [b2, c2] : cnt) {
                if (b1 + b2 >= k) {
                    ans += c1*c2;
                }
            }
        }
        
        return ans;
    }
};