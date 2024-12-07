class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        using ll = long long;
        const int n = nums.size();
        
        int left = 1;
        int right = 1e9;
        int ans = 0;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            int ops = 0;
            for (int i = 0; i < n; ++i) {
                ops += max((int)ceil(nums[i]*1.0/mid) - 1, 0);
            }
            if (ops <= maxOperations) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};