class Solution {
public:
    int rev(int num) {
        int a = 0;
        while (num > 0) {
            a = a*10 + num % 10;
            num /= 10;
        }
        return a;
    }
    
    int countNicePairs(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        const int MOD = 1e9 + 7;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            ans = (ans + cnt[nums[i] - rev(nums[i])]) % MOD;
            cnt[nums[i] - rev(nums[i])]++;
        }
        return ans;
    }
};