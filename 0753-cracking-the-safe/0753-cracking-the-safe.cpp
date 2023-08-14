class Solution {
private:
    string ans;
    int n, k;
    unordered_set<string> visited;
    vector<string> s;
    int m;
    
public:
    bool dfs(string last) {
        if (visited.size() == m) {
            return true;
        }
        for (char c = 0; c < k; ++c) {
            string tmp = last + char(c + '0');
            if (!visited.count(tmp)) {
                visited.insert(tmp);
                ans.push_back(c + '0');
                if (dfs(tmp.substr(1))) {
                    return true;
                }
                ans.pop_back();
                visited.erase(tmp);
            }
        }
        return false;
    }
    
    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        this->m = pow(k, n);
        string start = "";
        for (int i = 0; i < n - 1; ++i) {
            start.push_back('0');
        }
        ans = start;
        dfs(start);
        return ans;
    }
};