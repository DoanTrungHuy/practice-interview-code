class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> line(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                line[i] += line[i - 1];
            }
            int curr = nums[i] + line[i];
            if (curr < 0) {
                return false;
            }
            if (curr == 0) {
                continue;
            }
            if (i + k <= n) {
                line[i] -= curr;
                line[i + k] += curr;
            }
            if (nums[i] + line[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};