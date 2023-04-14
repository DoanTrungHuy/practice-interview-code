class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        const int n = queries.size();
        vector<int> ans;
        
        for (vector<int> query : queries) {
            int x1 = query[0];
            int y1 = query[1];
            int r = query[2];
            int cnt = 0;
            for (vector<int> point : points) {
                int x2 = point[0];
                int y2 = point[1];
                
                if ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) <= r*r) {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
            
        return ans;
    }
};