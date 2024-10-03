class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
        int t = 0;
        
        for (int i = 0; i < n; ++i) {
            t = (t + nums[i]) % k;
        }
        
        if (t == 0) {
            return 0;
        }
        
        unordered_map<int, int> pi;
        pi[0] = 0;
        int ans = n;

        for (int i = 0, s = 0; i < n; ++i) {
            (s += nums[i]) %= k;
            if (pi.count((t + (-s%k + k) % k) % k)) {
                ans = min(ans, (i + 1 - pi[(t + (-s%k + k) % k) % k]));
            }
            pi[(-s%k + k) % k] = i + 1;
        }
        
        return ans == n ? - 1 : ans;
    }
};