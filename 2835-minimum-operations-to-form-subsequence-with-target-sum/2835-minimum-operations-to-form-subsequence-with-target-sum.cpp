class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        
        if (s < target*1LL) {
            return -1;
        }
        
        const int n = nums.size();
        multiset<long long> ms;
        
        for (int i = 0; i < n; ++i) {
            ms.insert(nums[i]);
        }
        
        int step = 0;
        
        while (true) {
            long long t = 0, v = -1;
            
            auto it = ms.end();
            
            do {
                it--;
                long long x = *it;
                if (t + x > target*1LL) {
                    v = x;
                    continue;
                }
                t += x;
            } while (it != ms.begin());
            
            if (t == target*1LL) {
                break;
            }
            
            ms.erase(ms.lower_bound(v));
            ms.insert(v / 2);
            ms.insert(v / 2);
            
            step++;
        }
        
        return step;
    }
};