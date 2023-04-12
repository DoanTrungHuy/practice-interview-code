class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int cnt[201] = {};
        
        for (int num : nums) {
            cnt[num + 100]++;
        }
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (cnt[a + 100] != cnt[b + 100]) {
                return cnt[a + 100] < cnt[b + 100];
            }
            else {
                return a > b;
            }
        });
        
        return nums;
    }
};