class Solution {
private:
    int ans;
    unordered_set<long long> us;
    
public:
    void dfs(string &s, int p) {
        const int n = s.size();
        if (p == n) {
            ans = max(ans, (int)us.size());
            return;
        }
        long long hash = 0;
        for (int i = p; i < n; ++i) {
            hash = hash*10 + s[i];
            if (!us.count(hash)) {
                us.insert(hash);
                dfs(s, i + 1);
                us.erase(hash);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        ans = 0;
        dfs(s, 0);
        return ans;
    }
};