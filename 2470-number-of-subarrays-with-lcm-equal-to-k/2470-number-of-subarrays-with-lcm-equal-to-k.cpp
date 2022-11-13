class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            bool check = false;
            for (int j = i; j < n; ++j) {
                if (k % nums[j]) {
                    break;
                }
                if (k == nums[j]) {
                    check = true;
                }
                if (check) {
                    res++;
                }
            }
        }
        return res;
    }
};