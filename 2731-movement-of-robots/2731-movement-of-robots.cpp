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
        
        ll total = 0, ans = 0;
        const ll MOD = 1e9 + 7;
        
        for (int i = 0; i < n; ++i) {
            ans = (ans + (1LL*nums[i]*i)%MOD - total)%MOD;
            total = (total + nums[i]) % MOD;
        }
        
        return (int)(ans + MOD)%MOD;
    }
};