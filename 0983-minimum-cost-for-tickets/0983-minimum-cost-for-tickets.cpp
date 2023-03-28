class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> us(days.begin(), days.end());
        
        const int year = 365;
        
        int dp[year + 1] = {};
        
        for (int i = 1; i <= year; ++i) {
            if (!us.count(i)) {
                dp[i] = dp[i - 1];
            }
            else {
                int prevDay1 = dp[max(0, i - 1)] + costs[0];
                int prevDay7 = dp[(max(0, i - 7))] + costs[1];
                int prevDay30 = dp[max(0, i - 30)] + costs[2];
                
                dp[i] = min({prevDay1, prevDay7, prevDay30});
            }
        }
        
        return dp[year];
    }
};