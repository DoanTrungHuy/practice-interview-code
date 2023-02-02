class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool b[201] = {false};
        for (int num : nums) {
            b[num + 100] = true;
        }
        int j = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (b[nums[i] + 100]) {
                nums[j++] = nums[i];
                b[nums[i] + 100] = false;
            }
        }
        return j;
    }
};