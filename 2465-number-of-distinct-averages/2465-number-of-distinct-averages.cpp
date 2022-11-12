class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<double> ms;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            ms.insert((double)(nums[i] + nums[n - 1 - i]) / 2);
        } 
        return ms.size();
    }
};