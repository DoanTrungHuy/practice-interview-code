class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == -1) {
                continue;
            }
            int cnt = 1, x = nums[i];
            nums[i] = -1;
            while (nums[x] != -1) {
                int temp = nums[x];
                nums[x] = -1;
                x = temp;
                cnt += 1;
            }
            res = max(res, cnt);
        }
        
        return res;
    }
};