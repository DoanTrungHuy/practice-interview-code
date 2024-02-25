class Solution {
public:
    bool is_valid(vector<int>& nums, vector<int>& changeIndices, int len) {
        unordered_map<int, int> last_index;
        
        for (int i = 0; i < len; ++i) {
            last_index[changeIndices[i] - 1] = i;
        }
        
        if (nums.size() != last_index.size()) {
            return false;
        }
        
        int cnt = 0;
        
        for (int i = 0; i < len; ++i) {
            if (last_index[changeIndices[i] - 1] == i) {
                if (cnt >= nums[changeIndices[i] - 1]) {
                    cnt -= nums[changeIndices[i] - 1];
                }
                else {
                    return false;
                }
            }
            else {
                cnt++;
            }
        }
        
        return true;
    }
    
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        const int n = nums.size();
        const int m = changeIndices.size();
        int left = 1, right = m;
        int ans = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (is_valid(nums, changeIndices, mid)) {
                cout << mid << '\n';
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};