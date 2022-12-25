class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        // j < i
        // a[i] + a[j] = target
        // a[i] = target - a[j] -> Giu chi muc j 
        // -> return [um[a[i]], i] -> [j, i]
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (um.find(nums[i]) != um.end()) {
                return {um[nums[i]], i};
            }
            um[target - nums[i]] = i;
        }
        return {-1, -1};
        // um[target - a[j]] = j
        // um[7] = 0
    }
};