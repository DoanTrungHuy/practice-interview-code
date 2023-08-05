class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int c = purchaseAmount % 10;
        if (c < 5) {
            return abs(100 - purchaseAmount / 10 *10);
        }
        return abs(100 - ((purchaseAmount + 10)/10)*10);
    }
};