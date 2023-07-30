class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        const int n = nums.size();
        int sum = 0, maxSum = INT_MIN;
        
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        
        maxSum = max(maxSum, sum);
        
        for (int i = k; i < n; ++i) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum*1.0/k;
    }
};