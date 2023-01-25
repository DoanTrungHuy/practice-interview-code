class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = (int)dist.size();
        int l = 1, r = 1e9;
        int ans = -1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            double trimTime = 0;
            for (int i = 0; i < n - 1; ++i) {
                trimTime += ceil(dist[i] * 1.0 / m);
            }
            trimTime += dist[n - 1] * 1.0 / m;
            if (trimTime <= hour) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return ans;
    }
};