class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 1s -> (10^6 -> 10^7)
        // N = nums.length
        // Time: O(N)
        
        unordered_set<int> hashSet;
        
        for (int num : nums) {
            if (hashSet.find(num) != hashSet.end()) {
                return true;
            }
            hashSet.insert(num);
        }
        
        return false;
    }
};