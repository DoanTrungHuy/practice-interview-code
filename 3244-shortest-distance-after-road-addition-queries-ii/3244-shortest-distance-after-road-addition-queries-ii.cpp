class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> s;
        
        for (int i = 0; i < n; ++i) {
            s.insert(i);
        }
        
        vector<int> ans;
        
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];
            
            auto it_l = s.upper_bound(l);
            auto it_r = s.lower_bound(r);
            
            s.erase(it_l, it_r);
            
            ans.push_back(s.size() - 1);
        }
        
        return ans;
    }
};