class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt1 = 0;
            bool check1 = false; 
            set<int> s1;
            for (int j = i; j < n - 1; j++) {
                if (s1.size() > 0 and (!s1.count(nums[j]) or !s1.count(nums[j + 1]))) {
                    continue;
                }
                
                if (!check1 and nums[j + 1] - nums[j] == 1) {
                    check1 = !check1;
                    cnt1++;
                    s1.insert(nums[j]);
                    s1.insert(nums[j + 1]);
                }
                else if (check1 and nums[j + 1] - nums[j] == -1) {
                    check1 = !check1;
                    cnt1++;
                    s1.insert(nums[j]);
                    s1.insert(nums[j + 1]);
                }
                else {
                    break;
                }
            }
            
            ans = max(ans, cnt1 + 1);
        }
        
        return ans <= 1 ? -1 : ans;
    }
};