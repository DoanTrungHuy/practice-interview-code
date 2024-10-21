class Solution {
private:
    int ans;
    unordered_set<string> us;
    
public:
    void dfs(string &s, int p) {
        const int n = s.size();
        if (p == n) {
            ans = max(ans, (int)us.size());
            return;
        }
        string tmp;
        for (int i = p; i < n; ++i) {
            tmp += s[i];
            if (!us.count(tmp)) {
                us.insert(tmp);
                dfs(s, i + 1);
                us.erase(tmp);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        ans = 0;
        dfs(s, 0);
        return ans;
    }
};