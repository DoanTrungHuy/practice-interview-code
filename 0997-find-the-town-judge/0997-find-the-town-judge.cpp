class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> check(n + 1);
        const int inf = 1e9;
        
        for (auto t : trust) {
            check[t[0]] = inf;
            check[t[1]] += 1;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (check[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};