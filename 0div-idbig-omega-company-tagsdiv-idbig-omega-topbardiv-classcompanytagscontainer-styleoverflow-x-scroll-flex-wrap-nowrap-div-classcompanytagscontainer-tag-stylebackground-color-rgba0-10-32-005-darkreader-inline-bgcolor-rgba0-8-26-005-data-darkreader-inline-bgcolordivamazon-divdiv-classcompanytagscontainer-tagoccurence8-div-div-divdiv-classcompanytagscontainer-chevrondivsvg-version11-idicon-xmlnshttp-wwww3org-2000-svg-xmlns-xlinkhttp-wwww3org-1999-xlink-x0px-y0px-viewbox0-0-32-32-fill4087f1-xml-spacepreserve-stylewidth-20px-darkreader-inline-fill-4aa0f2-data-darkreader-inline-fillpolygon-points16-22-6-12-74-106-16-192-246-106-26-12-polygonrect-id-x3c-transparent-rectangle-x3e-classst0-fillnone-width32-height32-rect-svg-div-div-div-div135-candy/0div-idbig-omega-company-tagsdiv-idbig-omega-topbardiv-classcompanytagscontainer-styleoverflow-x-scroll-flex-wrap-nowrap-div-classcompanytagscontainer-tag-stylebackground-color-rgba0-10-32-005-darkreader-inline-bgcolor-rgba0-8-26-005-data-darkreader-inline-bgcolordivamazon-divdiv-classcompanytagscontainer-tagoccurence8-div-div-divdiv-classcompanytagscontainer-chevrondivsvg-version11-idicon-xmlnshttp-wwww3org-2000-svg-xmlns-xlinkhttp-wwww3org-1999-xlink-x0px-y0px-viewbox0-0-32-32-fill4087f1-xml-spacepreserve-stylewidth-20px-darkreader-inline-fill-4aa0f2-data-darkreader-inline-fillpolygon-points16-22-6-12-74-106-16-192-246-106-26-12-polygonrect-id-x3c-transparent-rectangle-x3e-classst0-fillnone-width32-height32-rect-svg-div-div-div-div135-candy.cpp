class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n - 1; ++i) {
            if (ratings[i] < ratings[i + 1]) {
                ans[i + 1] = ans[i] + 1;
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                ans[i] = max(ans[i + 1] + 1, ans[i]);
            }
        }
        
        return accumulate(ans.begin(), ans.end(), 0) + n;
    }
};