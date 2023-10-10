class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        vector<int> unums;
        for (int x : s) {
            unums.push_back(x);
        }
        const int m = unums.size();
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int j = upper_bound(unums.begin() + i, unums.end(), unums[i] + n - 1) - unums.begin();
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};