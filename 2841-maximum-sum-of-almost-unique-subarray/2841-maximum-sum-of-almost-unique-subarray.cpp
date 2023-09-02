class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0;
        long long s = 0;
        const int n = nums.size();
        unordered_map<int, int> um;
        
        for (int i = 0, j = 0; i < n; ++i) {
            um[nums[i]]++;
            s += nums[i];
            if (i - j + 1 == k) {
                if (um.size() >= m) {
                    ans = max(ans, s);
                }
                s -= nums[j];
                if (--um[nums[j]] == 0) {
                    um.erase(nums[j]);
                }
                j++;
            }
        }
        
        return ans;
    }
};