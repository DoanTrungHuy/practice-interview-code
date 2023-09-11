class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> um;
        const int n = groupSizes.size();
        
        for (int i = 0; i < n; ++i) {
            um[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> ans;
        
        for (const auto [size, group] : um) {
            vector<int> tmp;
            for (int member : group) {
                tmp.push_back(member);
                if (tmp.size() == size) {
                    ans.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        
        return ans;
    }
};