class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<pair<int, int>> p_nums;
        const int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            p_nums.push_back({nums[i], i});
        }
        
        sort(p_nums.begin(), p_nums.end());
        
        for (int i = 0; i < n; ++i) {
            int left = 0, right = n - 1;
            int min_ = n;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (p_nums[mid].first - nums[i] >= valueDifference) {
                    right = mid - 1;
                    min_ = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            for (int j = min_; j < n; ++j) {
                if (abs(i - p_nums[j].second) >= indexDifference) {
                    return {i, p_nums[j].second};
                }
            }
        }
        
        return {-1, -1};
    }
};