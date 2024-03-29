class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, long long> um;
        int target = *max_element(nums.begin(), nums.end());
        int j = 0;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            um[nums[i]]++;
            while (j <= i and um[target] >= k) {
                um[nums[j++]]--;
            }
            ans += i + 1;
            ans -= i - j + 1;
        }
        return ans;
    }
};