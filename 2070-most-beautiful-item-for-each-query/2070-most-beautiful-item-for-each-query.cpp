// class SegmentTree {
  
// };

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int m = queries.size();
        const int n = items.size();
        using pii = pair<int, int>;
        vector<pii> p_queries;
        
        for (int i = 0; i < m; ++i) {
            p_queries.push_back({queries[i], i});
        }
        
        sort(p_queries.begin(), p_queries.end());
        sort(items.begin(), items.end());
        
        vector<int> ans(m);
        int curr_max = 0;
                
        for (int i = 0, j = 0; i < m; ++i) {
            auto [limit_price, k] = p_queries[i];
            
            while (j < n && items[j][0] <= limit_price) {
                curr_max = max(curr_max, items[j][1]);
                j++;
            }
            
            ans[k] = curr_max;
        }
        
        return ans;
    }
};