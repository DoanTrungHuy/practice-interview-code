class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> line(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                line[i] += line[i - 1];
            }
            nums[i] += line[i];
            if (nums[i] < 0) {
                return false;
            }
            if (nums[i] == 0) {
                continue;
            }
            if (i + k <= n) {
                line[i] -= nums[i];
                line[i + k] += nums[i];
                nums[i] = 0;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                return false;
            }
        }
        
        return true;
    }
};