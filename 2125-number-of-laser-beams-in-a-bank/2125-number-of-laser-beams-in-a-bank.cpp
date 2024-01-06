class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        int total = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt[i] += bank[i][j] == '1';
            }
        }
        
        int prev = 0;
        
        for (int i = 0; i < n; ++i) {
            if (cnt[i]) {
                total += cnt[i] * prev;
                prev = cnt[i];
            }
        }
        
        return total;
    }
};