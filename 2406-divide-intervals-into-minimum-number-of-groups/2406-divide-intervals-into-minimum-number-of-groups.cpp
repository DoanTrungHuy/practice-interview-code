class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int MAXN = 1e6;
        int line[MAXN + 2];
        memset(line, 0, sizeof(line));
        
        for (auto it : intervals) {
            int x = it[0], y = it[1];
            line[x]++;
            line[y + 1]--;
        }
        
        int maxPossible = 0;
        
        for (int i = 1; i < MAXN - 1; ++i) {
            line[i] += line[i - 1];
            maxPossible = max(maxPossible, line[i]);
        }
        
        return maxPossible;
    }
};