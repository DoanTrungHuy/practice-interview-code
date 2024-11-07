class Solution {
public:
    int largestCombination(vector<int>& c) {
        const int n = c.size();
        int cnt[32] = {};
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (c[i]) {
                cnt[j] += c[i]&1;
                c[i] >>= 1;
                ans = max(ans, cnt[j]);
                j++;
            }
        }
        
        return ans;
    }
};