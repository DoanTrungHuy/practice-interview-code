class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
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