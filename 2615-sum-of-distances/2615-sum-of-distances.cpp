class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        const int n = nums.size();
        using ll = long long;
        unordered_map<int, vector<int>> um;
        
        for (int i = 0; i < n; ++i) {
            um[nums[i]].push_back(i);
        }
        
        vector<ll> ans(n);
        
        for (auto [val, indexs] : um) {
            const int m = indexs.size();
            ll len = 0, sum = 0;
            for (int i = 0; i < m; ++i) {
                ans[indexs[i]] += len * indexs[i] - sum;
                len++, sum += indexs[i];
            }
            len = 0, sum = 0;
            for (int i = m - 1; i >= 0; --i) {
                ans[indexs[i]] += sum - len * indexs[i];
                len++, sum += indexs[i];
            }
        }
        
        return ans;
    }
};