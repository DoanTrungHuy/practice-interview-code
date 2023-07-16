class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int MAXN = 200002;
        int line[MAXN] = {};
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int left = max(0, nums[i] - k);
            int right = nums[i] + k;
            
            line[left]++;
            line[right + 1]--;
        }
        
        int maxChange = 0;
        
        for (int i = 0; i < MAXN; ++i) {
            if (i > 0) {
                line[i] += line[i - 1];
            }
            maxChange = max(maxChange, line[i]);
        }
        
        return maxChange;
    }
};