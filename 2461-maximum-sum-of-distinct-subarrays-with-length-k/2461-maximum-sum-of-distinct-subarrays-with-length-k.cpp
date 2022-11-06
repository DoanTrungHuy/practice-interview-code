class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> us;
        int n = nums.size();
        long long s = 0;
        int j = 0;
        long long maxEle = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n and us.size() and us.find(nums[i]) != us.end()) {
                us.erase(nums[j]);
                s -= nums[j++];
            }
            s += 1LL * nums[i];
            us.insert(nums[i]);
            if (k < us.size()) {
                us.erase(nums[j]);
                s -= nums[j++];
            }
            cout << s << '\n';
            if (us.size() == k) {
                maxEle = max(maxEle, s);
            }
        }
        return maxEle;
    }
};