class Solution {
public:
    int bestClosingTime(string customers) {
        const int n = customers.size();
        int p[2][n + 1];
        memset(p, 0, sizeof(p));
        
        for (int i = 0; i < n; ++i) {
            p[0][i + 1] = p[0][i] + (customers[i] == 'N');
        }
        
        for (int i = n - 1; i >= 0; --i) {
            p[1][i] = p[1][i + 1] + (customers[i] == 'Y');
        }
        
        int min_penalty[2] = {-1, n};
        
        for (int i = 0; i <= n; ++i) {
            int calc_penalty = (p[0][i] - p[0][0]) + (p[1][i] - p[1][n]);
            
            if (calc_penalty < min_penalty[1]) {
                min_penalty[1] = calc_penalty;
                min_penalty[0] = i;
            }
        }
        
        return min_penalty[0];
    }
};