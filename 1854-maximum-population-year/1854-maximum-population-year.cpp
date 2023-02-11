class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        const int maxn = 2051;
        vector<int> line(maxn);
        for (auto log : logs) {
            int u = log[0];
            int v = log[1];
            line[u]++;
            line[v]--;
        }
        for (int i = 1; i < maxn; ++i) {
            line[i] += line[i - 1];
        }
        int ans = -1, year = -1;
        for (int i = 0; i < maxn; ++i) {
            if (ans < line[i]) {
                ans = line[i], year = i;
            }
        } 
        return year;
    }
};