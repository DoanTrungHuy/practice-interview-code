class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        const int n = nums.size();
        vector<int> n_nums;
        
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                n_nums.push_back(1);
            }
            else if (nums[i] == nums[i + 1]) {
                n_nums.push_back(0);
            }
            else {
                n_nums.push_back(-1);
            }
        }
        
        const int m = n_nums.size();
        const int BASE = 24;
        const int MOD = 1e9 + 7;
        
        long long hash_b = 0;
        
        for (int num : pattern) {
            hash_b = (hash_b*BASE + num + 108) % MOD;
        }
        
        vector<long long> hash_(m + 1);
        vector<long long> power(m + 1);
        
        power[0] = 1;
        
        for (int i = 0; i < m; ++i) {
            hash_[i + 1] = (hash_[i]*BASE + n_nums[i] + 108) % MOD;
            power[i + 1] = (power[i]*BASE) % MOD;
        }
        
        const auto get_hash = [&](int left, int right) -> long long {
            left++;
            right++;
            return (hash_[right] - (hash_[left - 1]*power[right - left + 1]) % MOD + MOD) % MOD;
        };
        
        int ans = 0;
        const int k = pattern.size();
        
        for (int i = 0; i < m - k + 1; ++i) {
            if (get_hash(i, i + k - 1) == hash_b) {
                ans++;
            }
        }
        
        return ans;
    }
};