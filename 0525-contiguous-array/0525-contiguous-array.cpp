class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> um;
        int line = 0, ans = 0;
        const int n = nums.size();
        
        um[0] = -1;
        
        for (int i = 0; i < n; ++i) {
            line += nums[i] == 1 ? -1 : 1;
            
            if (um.count(line)) {
                ans = max(ans, i - um[line]);
            }
            else {
                um[line] = i;
            }
        }
        
        return ans;
    }
};