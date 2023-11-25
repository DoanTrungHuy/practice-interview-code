class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        const int n = nums.size();
        vector<int> pref(n + 1);
        unordered_map<int, int> last_index;
        
        for (int i = 0; i < n; ++i) {
            last_index[tmp[i]] = i;
            pref[i + 1] = pref[i] + tmp[i];
        }
        
        auto get_sum = [&](int l, int r) {
            return pref[r + 1] - pref[l];
        };
        
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            int lb = last_index[tmp[i]] + 1;
            ans[i] += tmp[i]*lb - get_sum(0, last_index[tmp[i]]);
            int rb = n - 1 - last_index[tmp[i]] + 1;
            ans[i] += get_sum(last_index[tmp[i]], n - 1) - tmp[i]*rb;
        }
        
        return ans;
    }
};