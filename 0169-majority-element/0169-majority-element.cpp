class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int vote = 1;
        int candidate = nums[0];
        for (int i = 1; i < n; ++i) {
            if (!vote) {
                vote = 0;
                candidate = nums[i];
            }
            vote += candidate == nums[i] ? 1 : -1;
        }
        return candidate;
    }
};