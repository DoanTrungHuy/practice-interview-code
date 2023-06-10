using ll = long long;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                nums[i] -= d;
            }
            else {
                nums[i] += d;
            }
        }
        
        sort(nums.begin(), nums.end());
        ll ans = 0, pref = 0;
        const ll MOD = 1e9 + 7;
        
        for (int i = 0; i < n; ++i) {
            ans = (ans + 1LL*nums[i]*i - pref) % MOD;
            pref = (pref + nums[i]) % MOD;
        }
        
        return ans;
    }
};