class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int cnt[100000] = {0};
        int m = INT_MIN;
        for (int num : nums) {
            cnt[num]++;
            if (!(num % 2)) {
                m = max(m, cnt[num]);
            }
        }
        int ans = INT_MAX;
        for (int num : nums) {
            if (num % 2) {
                continue;
            }
            if (m == cnt[num]) {
                ans = min(ans, num);
            }
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};