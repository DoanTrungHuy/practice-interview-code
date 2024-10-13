class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using pii = pair<int, int>;
        set<pii> s;
        const int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)nums[i].size(); ++j) {
                s.insert({nums[i][j], i});
            }
        }
        
        vector<pii> flatten(s.begin(), s.end());        
        vector<int> ans;
        const int sz = flatten.size();
        unordered_map<int, int> um;
        
        for (int j = 0, i = 0; i < sz; ++i) {
            um[flatten[i].second]++;
            
            while (um.size() == n) {
                if (ans.empty() || flatten[i].first - flatten[j].first < ans[1] - ans[0]) {
                    ans = {flatten[j].first, flatten[i].first};
                }
                um[flatten[j].second]--;
                if (!um[flatten[j].second]) {
                    um.erase(flatten[j].second);
                }
                j++;
            }
        }
        
        return ans;
    }
};