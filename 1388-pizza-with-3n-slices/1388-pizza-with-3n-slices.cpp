const int MN = 5e2 + 1;
int memo[MN][MN/3 + 1];

class Solution {
private:
    vector<int> slices;
    
public:    
    int dp(int i, int pick, int end) {
        if (i >= end or pick == 0) {
            return 0;
        }
        
        if (memo[i][pick] != -1) {
            return memo[i][pick];
        }
        
        return memo[i][pick] = max({
            slices[i] + dp(i + 2, pick - 1, end),
            dp(i + 1, pick, end)
        });
    } 
    
    int maxSizeSlices(vector<int>& slices) {
        this->slices = slices;
        int n = slices.size();
        memset(memo, -1, sizeof(memo));
        int k = n / 3;
        int ans = dp(0, k, n - 1);
        memset(memo, -1, sizeof(memo));
        return max(ans, dp(1, k, n));
    }
};