class Solution {
private:
    vector<int> subsets;
    int ans, n;
    
public:
    void dfs(int i, vector<int> &tasks, int sessionTime) {
        if (i == n) {
            ans = min(ans, (int)subsets.size());
            return;
        }
        
        if (subsets.size() >= ans) {
            return;
        }
        
        for (int j = 0; j < subsets.size(); ++j) {
            if (subsets[j] + tasks[i] <= sessionTime) {
                subsets[j] += tasks[i];
                dfs(i + 1, tasks, sessionTime);
                subsets[j] -= tasks[i];
            }
        }
        
        subsets.push_back(tasks[i]);
        dfs(i + 1, tasks, sessionTime);
        subsets.pop_back();
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        ans = INT_MAX;
        n = tasks.size();
        dfs(0, tasks, sessionTime);
        return ans;
    }
};