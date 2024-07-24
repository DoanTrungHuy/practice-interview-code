const int MN = 2e5;

int memo[MN][3];

class Solution {
public:
    int dp(vector<int> &a, vector<int> &b, int i, int state) {
        if (i == (int)a.size()) {
            return 0;
        }
        
        if (memo[i][state] != -1) {
            return memo[i][state];
        }
        
        int ans = 0;
        
        if (state == 0) {
            ans = max(a[i] + dp(a, b, i + 1, state), b[i] + dp(a, b, i + 1, state + 1));
        }
        else if (state == 1) {
            ans = max(b[i] + dp(a, b, i + 1, state), a[i] + dp(a, b, i + 1, state + 1));
        }
        else {
            ans = a[i] + dp(a, b, i + 1, state);
        }
        
        return memo[i][state] = ans;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        memset(memo, -1, sizeof(memo));
        int ans = dp(nums1, nums2, 0, 0);
        memset(memo, -1, sizeof(memo));
        return max(ans, dp(nums2, nums1, 0, 0));
    }
};