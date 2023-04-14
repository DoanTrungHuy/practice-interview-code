class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxFreq = 0;
        const int n = nums.size();
        int cnt[50000] = {};
        unordered_map<int, int> indexs;
        int res = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            cnt[nums[i]]++;
            if (!indexs.count(nums[i])) {
                indexs[nums[i]] = i;
            }
            if (maxFreq == cnt[nums[i]]) {
                res = min(res, i - indexs[nums[i]] + 1);
            }
            else if (maxFreq < cnt[nums[i]]) {
                maxFreq = cnt[nums[i]];
                res = i - indexs[nums[i]] + 1;
            }
        }
        
        return res;
    }
};