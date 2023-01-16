class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cntZero = 0;
        int n = nums.size();
        int j = 0;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                cntZero++;
            }
            while (j < n and k < cntZero) {
                if (nums[j] == 0) {
                    cntZero--;
                }
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};