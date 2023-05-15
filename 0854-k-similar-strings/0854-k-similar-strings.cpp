class Solution {
private:
    int n;
    string s1, s2;
    
public:
    int dfs(int i) {
        if (i == n) {
            return 0;
        }
        if (s1[i] == s2[i]) {
            return dfs(i + 1);
        }
        int ans = 1e9;
        for (int j = i + 1; j < n; ++j) {
            swap(s1[i], s1[j]);
            if (s1[i] == s2[i] and s1[i] != s2[j]) {
                ans = min(ans, 1 + dfs(i + 1));
            }
            swap(s1[i], s1[j]);
        }
        return ans;
    }
    int kSimilarity(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        this->n = s1.size();
        string t1, t2;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i]) {
                t1 += s1[i];
                t2 += s2[i];
            }
        }
        s1 = t1, s2 = t2;
        return dfs(0);
    }
};