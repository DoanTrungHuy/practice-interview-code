class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt_one = 0;
        const int n = nums.size();
        
        // Count the number of 1s in the original array
        for (int i = 0; i < n; ++i) {
            cnt_one += nums[i];
        }
        
        // Duplicate the array to handle the circular nature
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        int ans = INT_MAX;
        int cnt_zero = 0;
        int j = 0;
        
        // Use a sliding window approach
        for (int i = 0; i < 2 * n; ++i) {
            cnt_zero += nums[i] == 0;
            
            // Ensure the window size is not greater than cnt_one
            while (i - j + 1 > cnt_one) {
                cnt_zero -= nums[j] == 0;
                j++;
            }
            
            // Check if the current window size is exactly cnt_one
            if (i - j + 1 == cnt_one) {
                ans = min(ans, cnt_zero);
            }
        }
        
        return ans;
    }
};
