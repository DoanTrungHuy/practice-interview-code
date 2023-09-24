class Solution {
private:
    vector<int> nums;
    
public:
    void dfs(int i, int sz, vector<vector<int>> &sub_set, int s, int len) {
        if (i == sz) {
            sub_set[len].push_back(s);
            return;
        }    
        dfs(i + 1, sz, sub_set, s + nums[i], len + 1);
        dfs(i + 1, sz, sub_set, s - nums[i], len);
    }
    
    int minimumDifference(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        vector<vector<int>> sub_sets[2];
        int m = n/2;
        sub_sets[0].resize(m + 1);
        sub_sets[1].resize(m + 1);
        dfs(0, m, sub_sets[0], 0, 0);
        dfs(m, n, sub_sets[1], 0, 0);
        for (int i = 0; i <= m; ++i) {
            sort(sub_sets[0][i].begin(), sub_sets[0][i].end());
        }
        int ans = INT_MAX;
        for (int len = 0; len <= m; ++len) {
            for (int a : sub_sets[1][len]) {
                auto it = lower_bound(sub_sets[0][m - len].begin(), sub_sets[0][m - len].end(), -a);
                if (it != sub_sets[0][m - len].end()) {
                    ans = min(ans, abs(a + *it));
                }
                if (it != sub_sets[0][m - len].begin()) {
                    ans = min(ans, abs(a + *prev(it)));
                }
            }
        }
        return ans;
    }
};