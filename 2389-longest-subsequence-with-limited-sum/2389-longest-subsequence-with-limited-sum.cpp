class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int m = queries.size();
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            ans.push_back(upper_bound(
                prefixSum.begin(), prefixSum.end(), queries[i]) - prefixSum.begin() - 1);
        }
        return ans;
    }
};