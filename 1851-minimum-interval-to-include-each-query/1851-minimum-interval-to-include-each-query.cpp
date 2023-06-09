#define START 0
#define END 1
#define QUERY 2

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        map<int, set<pair<int, int>>> line;
        int n = intervals.size();
        
        for (int i = 0; i < n; ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int len = end - start + 1;
            line[start].insert({START, len});
            line[end + 1].insert({END, len});
        }
        
        int m = queries.size();
        
        for (int i = 0; i < m; ++i) {
            line[queries[i]].insert({QUERY, i});
        }
        
        vector<int> ans(m, -1);
        multiset<int> sizes;
        
        for (auto [_, times] : line) {
            for (auto [choose, size_or_index] : times) {
                if (choose == START) {
                    sizes.insert(size_or_index);
                }
                else if (choose == END) {
                    sizes.erase(sizes.find(size_or_index));
                }
                else if (choose == QUERY and !sizes.empty()) {
                    ans[size_or_index] = *sizes.begin();
                }
            }
        }
        
        return ans;
    }
};