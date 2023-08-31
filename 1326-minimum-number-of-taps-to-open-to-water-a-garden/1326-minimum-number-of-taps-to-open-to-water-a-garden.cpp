const int MN = 1e4;
int memo[MN];
using ar = array<int, 2>;
const int INF = 1e8;

class Solution {
private:
    vector<ar> events;
    int n, m;
    
public:
    int dp(int i) {
        if (events[i][1] == n) {
            return 1;
        }
        if (i == m) {
            return INF;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int ans = INF;
        for (int j = i + 1; j < m; ++j) {
            if (events[i][1] < events[j][0]) {
                break;
            }
            ans = min(ans, 1 + dp(j));
        }
        return memo[i] = ans;
    }
    
    int minTaps(int n, vector<int>& ranges) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        this->m = ranges.size();
        
        for (int i = 0; i < m; ++i) {
            events.push_back({
                max(0, i - ranges[i]), 
                min(n, i + ranges[i])
            });
        }
        
        sort(events.begin(), events.end(), [&](const ar a, const ar b){
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int ans = INF;
        
        for (int i = 0; i < m; ++i) {
            int start = events[i][0];
            int end = events[i][1];
            
            if (start == 0) {
                ans = min(ans, dp(i));
                break;
            }
        }
        
        return ans == INF ? -1 : ans;
    }
};