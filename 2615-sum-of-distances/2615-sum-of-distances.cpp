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
                len++, sum += indexs[i];
                ans[indexs[i]] += len * indexs[i] - sum;
            }
            len = 0, sum = 0;
            for (int i = m - 1; i >= 0; --i) {
                len++, sum += indexs[i];
                ans[indexs[i]] += sum - len * indexs[i];
            }
        }
        
        return ans;
    }
};