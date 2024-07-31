int memo[1001];

class Solution {
private:
    vector<vector<int>> books;
    int shelfWidth;
    int n;
    
public:
    int dp(int i) {
        if (i == n) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int total_placed = 0;
        int ans = 1e9;
        int max_placed = 0;
        for (int j = i; j < n; ++j) {
            total_placed += books[j][0];
            max_placed = max(max_placed, books[j][1]);
            if (total_placed > shelfWidth) {
                break;
            }
            ans = min(ans, max_placed + dp(j + 1));
        }
        return memo[i] = ans;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this->books = books;
        this->n = books.size();
        this->shelfWidth = shelfWidth;
        memset(memo, -1, sizeof(memo));
        return dp(0);
    }
};