class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        const int MN = 1001;
        const int n = nums.size();
        vector<int> primes;
        bool visited[MN] = {false};
        visited[0] = visited[1] = true;
        
        for (int i = 2; i < MN; ++i) {
            if (!visited[i]) {
                for (int j = 2*i; j < MN; j += i) {
                    visited[j] = true; 
                }
                primes.push_back(i);
            }
        }
        
        int target = 0;
        
        for (int i = 0; i < n; ++i) {
            int p = INT_MAX;
            int left = 0, right = primes.size() - 1;
            
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (nums[i] - primes[mid] > target) {
                    p = primes[mid];
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
                        
            if (p == INT_MAX and nums[i] <= target) {
                return false;
            }
            else if (p == INT_MAX and nums[i] > target) {
                target = nums[i];
            }
            else {
                target = nums[i] - p;
            }
        }
        
        return true;
    }
};