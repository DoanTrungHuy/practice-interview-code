class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Time: O(N)
        // Ky thuat Kadane
        
        int maxSum = 0, ans = INT_MIN;
        
        for (int num : nums) {
            maxSum = max(maxSum + num, num);
            ans = max(ans, maxSum);
        }
        
        // nums = [-2,1,-3,4,-1,2,1,-5,4]
        // maxSum = -2, num = 1
        // max(-2 + 1, 1)
        
        return ans;
    }
};