class Solution {
private:
    vector<int> cuts;
    
public:
    int memo[102][102];
    
    int dp(int left, int right) {
        if (right - left == 1) {
            return 0;
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        int res = INT_MAX;
        for (int mid = left + 1; mid < right; ++mid) {
            res = min(res, cuts[right] - cuts[left] + dp(left, mid) + dp(mid, right));
        }
        return memo[left][right] = res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(memo, -1, sizeof(memo));
        this->cuts = cuts;
        return dp(0, cuts.size() - 1);
    }
};