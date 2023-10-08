int memo[501][501];

class Solution {
private:
    vector<int> nums1, nums2;
    int n, m;
    
public:
    int dp(int i, int j) {
        if (j == m or i == n) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        return memo[i][j] = max({
            dp(i + 1, j + 1) + nums1[i] * nums2[j],
            dp(i + 1, j),
            dp(i, j + 1)
        });
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        this->n = nums1.size();
        this->m = nums2.size();
        memset(memo, -1, sizeof(memo));
        int max_pos = dp(0, 0);
        if (max_pos == 0) {
            return max({
                nums1[0]*nums2[m - 1],
                nums1[n - 1]*nums2[0],
            });

        }
        return max_pos;
    }
};