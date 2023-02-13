class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = INT_MAX;
        
        for (int price : prices) {
            profit = max(profit, price - buy);
            buy = min(buy, price);
        }
        
        return profit;
    }
};