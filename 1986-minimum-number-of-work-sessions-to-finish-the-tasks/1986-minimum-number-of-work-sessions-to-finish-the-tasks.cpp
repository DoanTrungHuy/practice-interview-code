int dp[1 << 15][150];

class Solution {
private:
    int n, target;
    
public:
    int dfs(int mask, int sum, vector<int>& tasks, int sessionTime) {
        if (mask == target) {
            return 1;
        }
        
        if (dp[mask][sum] != -1) {
            return dp[mask][sum];
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                continue;
            }
            
            int newMask = mask | (1 << i);
            
            if (sum + tasks[i] > sessionTime) {
                ans = min(ans, 1 + dfs(newMask, tasks[i], tasks, sessionTime));
            }
            else {
                ans = min(ans, dfs(newMask, sum + tasks[i], tasks, sessionTime));
            }
        }
        
        return dp[mask][sum] = ans;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        target = (1 << n) - 1;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, tasks, sessionTime);
    }
};