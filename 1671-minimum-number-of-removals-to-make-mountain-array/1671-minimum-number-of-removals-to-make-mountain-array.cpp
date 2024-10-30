class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // Đầu tiên là tìm dãy con tăng dần dài nhất từ phía bên trái
        // Tiếp theo thì mình cũng tìm dãy con tăng dần dài nhất từ phải sang
        const int n = nums.size();
        int dp1[n + 1];
        
        // duyệt for i -> n - 1 check for j -> i - 1
        // sẽ pick những thằng nhỏ nums[j] < nums[i]
        // dp[i] = max(dp[i], dp[j] + 1) gọi là độ dài tại thời điểm i lớn nhất khi chọn thử các phương án trước (j < i);
        
        int dp2[n + 1];
        
        for (int i = 0; i < n; ++i) {
            dp1[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            dp2[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[i]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        
        int max_mountain = 0;
        
        for (int i = 0; i < n; ++i) {
            if (dp1[i] == 1 || dp2[i] == 1) {
                continue;
            }
            max_mountain = max(max_mountain, dp1[i] + dp2[i] - 1);
        }
        
        return n - max_mountain;
    }
};