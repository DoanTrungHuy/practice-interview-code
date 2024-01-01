class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        const int m = s.size();
        const int n = g.size();
        if (m == 0 or n == 0) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            if (s[i] >= g[j]) {
                j++;
            }
            if (j == n) {
                break;
            }
        }
        return j;
    }
};