class Solution {
private:
    vector<int> nums;
    int k;
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int n = nums.size();
        this->nums = nums;
        this->k = k;
        
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums[n - 1] - nums[0];
        int ans = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && nums[i] - nums[j] > mid) {
                    j++;
                }
                cnt += i - j; 
            }
            
            cout << mid << ' ' << cnt << '\n';
            
            if (cnt >= k) {
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