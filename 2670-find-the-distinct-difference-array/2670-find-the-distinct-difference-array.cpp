class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff;
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> us1, us2;
            for (int j = 0; j <= i; ++j) {
                us1.insert(nums[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                us2.insert(nums[j]);
            }
            diff.push_back(us1.size() - us2.size());
        }
        
        return diff;
    }
};