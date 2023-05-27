class Solution {
private:
    string s;
    unordered_set<string> us;
    int n;
    
public:
    int memo[51];
    
    int dp(int i) {
        if (i == n) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int res = INT_MAX;
        string dummy;
        for (int j = i; j < n; ++j) {
            dummy += s[j];
            if (us.count(dummy)) {
                res = min(res, dp(j + 1));
            }
        }
        res = min(res, dp(i + 1) + 1);
        return memo[i] = res;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(memo, -1, sizeof(memo));
        this->n = s.size();
        for (string str : dictionary) {
            us.insert(str);
        }
        this->s = s;
        return dp(0);
    }
};