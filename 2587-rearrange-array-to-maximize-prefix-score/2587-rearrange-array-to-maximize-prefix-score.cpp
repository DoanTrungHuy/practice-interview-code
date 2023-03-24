class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long s = 0;
        int cnt = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            s += nums[i];
            
            if (s > 0) {
                cnt++;
            }
            else {
                break;
            }
        }
        
        return cnt;
    }
};