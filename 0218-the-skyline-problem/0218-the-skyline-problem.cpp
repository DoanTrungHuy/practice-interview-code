class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> events;
        
        for (vector<int> build : buildings) {
            int x1 = build[0];
            int x2 = build[1];
            int height = build[2];
            
            events.push_back({x1, -height});
            events.push_back({x2, height});
        }
        
        sort(events.begin(), events.end());
        
        vector<vector<int>> ans;
        multiset<int> line{0};
        int top = 0;
        
        for (vector<int> event : events) {
            int curr = event[0];
            int height = event[1];
            
            if (height < 0) {
                line.insert(-height);
            }
            else {
                line.erase(line.lower_bound(height));
            }
            
            if (*line.rbegin() != top) {
                top = *line.rbegin();
                ans.push_back({curr, top});
            }
        }
        
        return ans;
    }
};