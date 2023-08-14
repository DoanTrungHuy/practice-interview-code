class Solution {
private:
    string ans;
    int n, k;
    unordered_set<string> visited;
    
public:
    void dfs(string last) {
        for (char c = 0; c < k; ++c) {
            string tmp = last + char(c + '0');
            if (!visited.count(tmp)) {
                visited.insert(tmp);
                dfs(tmp.substr(1));
                ans.push_back(c + '0');
            }
        }
    }
    
    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        string start = "";
        for (int i = 0; i < n - 1; ++i) {
            start.push_back('0');
        }
        dfs(start);
        return ans + start;
    }
};