class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pref;
        pref[0] = 1;
        int sum = 0, ans = 0;
        
        for (int num : nums) {
            sum += num;
            ans += pref[sum - k];
            pref[sum]++;
        }
        
        return ans;
    }
};