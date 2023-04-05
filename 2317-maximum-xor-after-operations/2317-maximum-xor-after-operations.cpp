class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            ans = ans | nums[i];
        }
        return ans;
    }
};