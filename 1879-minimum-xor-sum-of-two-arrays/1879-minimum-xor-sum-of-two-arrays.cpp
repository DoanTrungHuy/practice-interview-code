class Solution {
private:
    vector<int> nums1, nums2;
    int n, m;
    
public:
    int memo[14][1 << 14];
    
    int dp(int i, int mask) {
        if (mask == ((1 << n) - 1)) {
            return 0;
        }
        if (memo[i][mask] != -1) {
            return memo[i][mask];
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) {
                continue;
            }
            ans = min(ans, (nums1[i] ^ nums2[j]) + dp(i + 1, mask ^ (1 << j)));
        }
        return memo[i][mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(memo, -1, sizeof(memo));
        this->nums1 = nums1;
        this->nums2 = nums2;
        this->n = nums1.size();
        return dp(0, 0);
    }
};