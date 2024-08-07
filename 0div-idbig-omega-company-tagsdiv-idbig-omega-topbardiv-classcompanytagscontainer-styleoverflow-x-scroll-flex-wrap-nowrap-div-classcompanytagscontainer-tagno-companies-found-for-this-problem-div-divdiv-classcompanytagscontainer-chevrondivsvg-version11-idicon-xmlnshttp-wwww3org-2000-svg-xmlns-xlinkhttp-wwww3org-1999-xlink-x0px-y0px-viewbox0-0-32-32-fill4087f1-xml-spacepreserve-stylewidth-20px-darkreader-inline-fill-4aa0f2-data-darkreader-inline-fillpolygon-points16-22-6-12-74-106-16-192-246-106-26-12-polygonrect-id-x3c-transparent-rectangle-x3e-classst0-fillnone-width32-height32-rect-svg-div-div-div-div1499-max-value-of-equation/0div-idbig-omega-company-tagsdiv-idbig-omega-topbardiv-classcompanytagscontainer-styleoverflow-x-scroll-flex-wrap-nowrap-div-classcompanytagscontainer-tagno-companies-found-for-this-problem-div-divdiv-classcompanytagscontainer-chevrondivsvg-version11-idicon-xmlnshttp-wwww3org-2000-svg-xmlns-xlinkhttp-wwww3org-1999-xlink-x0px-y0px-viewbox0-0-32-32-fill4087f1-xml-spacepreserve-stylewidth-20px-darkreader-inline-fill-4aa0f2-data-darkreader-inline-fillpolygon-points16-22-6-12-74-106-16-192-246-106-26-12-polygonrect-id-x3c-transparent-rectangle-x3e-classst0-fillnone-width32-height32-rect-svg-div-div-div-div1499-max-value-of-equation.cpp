class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        const int n = points.size();
        int ans = INT_MIN;
        queue<int> mq;
        map<int, int> mm;
        
        // max([yi - xi]) + xj + yj
        
        for (int j = 0; j < n; ++j) {
            int xj = points[j][0];
            int yj = points[j][1];
            
            while (mq.size() and xj - points[mq.front()][0] > k) {
                int xi = points[mq.front()][0];
                int yi = points[mq.front()][1];
                mm[yi - xi]--;
                if (mm[yi - xi] == 0) {
                    mm.erase(yi - xi);
                }
                mq.pop();
            }
            
            if (mq.size()) {
                ans = max(ans, yj + xj + (*mm.rbegin()).first);
            }
            
            mq.push(j);
            mm[yj - xj]++;
        }
        
        return ans;
    }
};