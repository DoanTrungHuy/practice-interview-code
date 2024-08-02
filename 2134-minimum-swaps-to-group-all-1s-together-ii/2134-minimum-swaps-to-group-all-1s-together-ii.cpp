class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt_one = 0;
        const int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            cnt_one += nums[i];
        }
        
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        int ans = INT_MAX;
        int cnt_zero = 0;
        int j = 0;
        
        for (int i = 0; i < 2 * n; ++i) {
            cnt_zero += nums[i] == 0;
            
            while (i - j + 1 > cnt_one) {
                cnt_zero -= nums[j] == 0;
                j++;
            }
            
            if (i - j + 1 == cnt_one) {
                ans = min(ans, cnt_zero);
            }
        }
        
        return ans;
    }
};
