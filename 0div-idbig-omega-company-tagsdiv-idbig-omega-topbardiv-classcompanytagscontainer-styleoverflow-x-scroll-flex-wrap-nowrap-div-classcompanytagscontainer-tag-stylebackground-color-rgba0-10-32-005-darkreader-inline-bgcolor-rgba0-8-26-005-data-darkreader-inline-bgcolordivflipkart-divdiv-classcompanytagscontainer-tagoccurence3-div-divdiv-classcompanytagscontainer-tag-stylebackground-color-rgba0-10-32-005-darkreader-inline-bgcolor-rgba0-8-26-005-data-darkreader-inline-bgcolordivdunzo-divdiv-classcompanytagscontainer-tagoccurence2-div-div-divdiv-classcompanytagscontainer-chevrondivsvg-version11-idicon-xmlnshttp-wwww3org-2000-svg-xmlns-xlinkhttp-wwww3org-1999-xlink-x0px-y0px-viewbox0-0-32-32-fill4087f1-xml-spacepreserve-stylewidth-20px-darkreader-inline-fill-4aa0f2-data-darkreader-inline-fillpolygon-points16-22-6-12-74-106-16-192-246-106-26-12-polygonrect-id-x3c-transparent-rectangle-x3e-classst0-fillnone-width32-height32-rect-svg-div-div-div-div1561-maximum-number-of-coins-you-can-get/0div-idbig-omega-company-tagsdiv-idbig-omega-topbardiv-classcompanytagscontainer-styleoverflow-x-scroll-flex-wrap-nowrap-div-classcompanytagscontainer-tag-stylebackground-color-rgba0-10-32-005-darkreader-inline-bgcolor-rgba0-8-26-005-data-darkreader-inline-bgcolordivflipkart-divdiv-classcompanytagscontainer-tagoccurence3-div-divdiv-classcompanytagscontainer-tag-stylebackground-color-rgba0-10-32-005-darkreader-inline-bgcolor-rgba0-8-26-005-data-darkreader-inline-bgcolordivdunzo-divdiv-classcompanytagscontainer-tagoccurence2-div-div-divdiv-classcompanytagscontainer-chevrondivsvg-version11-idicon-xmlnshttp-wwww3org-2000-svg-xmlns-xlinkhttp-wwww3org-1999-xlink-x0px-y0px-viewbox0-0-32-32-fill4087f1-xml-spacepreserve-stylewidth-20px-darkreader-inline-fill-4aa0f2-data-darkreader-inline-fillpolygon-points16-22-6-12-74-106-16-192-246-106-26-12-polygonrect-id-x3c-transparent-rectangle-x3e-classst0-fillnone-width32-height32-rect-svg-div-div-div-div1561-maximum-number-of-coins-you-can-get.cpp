class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int ans = 0;
        
        for (int i = n - 2; i >= n / 3; i -= 2) {
            ans += piles[i];
        }
        
        return ans;
    }
};