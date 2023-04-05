using ll = long long;

class Solution {
public:
    ll getMax(vector<int> nums, ll mid) {
        const int n = nums.size();
        vector<ll> arr(n);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = 1LL * nums[i];
        }
        
        for (int i = n - 1; i >= 1; --i) {
            if (arr[i] <= mid) {
                continue;
            }
            arr[i - 1] += arr[i] - mid;
            arr[i] = mid;
        } 
        
        return *max_element(arr.begin(), arr.end());
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        ll left = 0, right = 1e9;
        
        while (left < right) {
            ll mid = left + (right - left) / 2;
            
            if (getMax(nums, mid) <= mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return (int)right;
    }
};