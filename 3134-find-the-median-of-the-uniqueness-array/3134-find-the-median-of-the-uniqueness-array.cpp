class Solution {
public:
    long long count_number(vector<int>& nums, int k) {
        unordered_map<long long, long long> cnt;
        const long long n = nums.size();
        long long j = 0;
        long long len = 0;
        for (int i = 0; i < n; ++i) {
            cnt[nums[i]]++;
            while (j < i and cnt.size() > k) {
                cnt[nums[j]]--;
                if (cnt[nums[j]] == 0) {
                    cnt.erase(nums[j]);
                }
                j++;
            }
            len += i - j + 1;
        }
        return len;
    }
    
    int medianOfUniquenessArray(vector<int>& nums) {
        long long n = nums.size();
        long long len = n * (n + 1) / 2;
        long long median = (len + 1) / 2;
        long long left = 1;
        long long right = n;
        long long ans = 1;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            
            if (count_number(nums, mid) >= median) {
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