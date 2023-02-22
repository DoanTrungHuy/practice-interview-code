class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> um;
        for (vector<int> d : dominoes) {
            int u = d[0];
            int v = d[1];
            int k = max(d[0], d[1]) * 10 + min(d[0], d[1]);
            um[k]++;
        }
        int ans = 0;
        for (auto [_, cnt] : um) {
            ans += (cnt - 1) * cnt / 2;
        }
        return ans;
    }
};