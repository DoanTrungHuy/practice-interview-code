class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int vote = 1;
        int candidate = nums[0];
        for (int i = 1; i < n; ++i) {
            if (!vote) {
                vote = 1;
                candidate = nums[i];
            }
            else if (candidate == nums[i]) {
                vote++;
            }
            else {
                vote--;
            }
        }
        return candidate;
    }
};