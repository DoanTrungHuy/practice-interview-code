class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0];
        
        while (left < right) {
            int mid = (right + left) / 2;
            
            int k = 0;
            
            for (int i = 0; i < n - 1 and k < p; ++i) {
                if (nums[i + 1] - nums[i] <= mid) {
                    k++;
                    i++;
                }
            }
            
            if (k >= p) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return right;
    }
};