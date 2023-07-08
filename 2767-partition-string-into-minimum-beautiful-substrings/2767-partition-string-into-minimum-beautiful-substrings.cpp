class Solution {
private:
    string s;
    int ans = INT_MAX;
    
public:
    bool checkF(string num) {
        int res = 0, cnt = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            if (num[i] == '1') {
                res += pow(2, cnt);
            }
            cnt++;
        }
        int i = 0;
        while (pow(5, i) <= res) {
            if (pow(5, i) == res) {
                return true;
            }
            i++;
        }
        return false;
    }
    
    void dfs(int i, int cnt = 0) {
        if (i == s.size()) {
            ans = min(ans, cnt);
            return;
        }
        
        string tmp;
        
        for (int j = i; j < s.size(); ++j) {
            tmp.push_back(s[j]);
            if (checkF(tmp) and tmp[0] != '0') {
                dfs(j + 1, cnt + 1);
            }
        }
    }
    
    int minimumBeautifulSubstrings(string s) {
        this->s = s;
        dfs(0);
        return ans == INT_MAX ? -1 : ans;
    }
};