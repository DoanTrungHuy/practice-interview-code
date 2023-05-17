class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; ++i) {
            int u1 = firstList[i][0];
            int u2 = firstList[i][1];
            for (int j = 0; j < m; ++j) {
                int v1 = secondList[j][0];
                int v2 = secondList[j][1];
                int c1 = max(u1, v1);
                int c2 = min(u2, v2);
                if (c1 > c2) {
                    continue;
                }
                ans.push_back({c1, c2});
            }
        }
        
        return ans;
    }
};