class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        const int n = nums.size();
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            set<int> s;
            vector<int> tmp;
            for (int j = 0; j < n; ++j) {
                if (s.find(nums[j]) == s.end() and visited[j] == false) {
                    tmp.push_back(nums[j]);
                    s.insert(nums[j]);
                    visited[j] = true;
                }
            }
            if (s.size()) {
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
};