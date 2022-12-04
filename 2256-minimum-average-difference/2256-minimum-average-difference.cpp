class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + 1LL*nums[i];
        }
        int diff = INT_MAX;
        int answ = 0;
        for (int i = 1; i <= n; ++i) {
            int j = n - i;
            int a = pre[i] / i;
            int b = !j ? 0 : (pre[n] - pre[i]) / j;
            int t = abs(a - b);
            if (diff > t) {
                diff = t;
                answ = i - 1;
            }
        }
        return answ;
    }
};