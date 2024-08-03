const long long MN = 1e5 + 10;
long long memo[MN][2];

const long long MOD = 1e9 + 7;

class Solution {
private:
    vector<int> nums1, nums2;
    unordered_map<long long, long long> um1, um2;
    
public:
    long long dp(long long i, long long state, long long n1, long long n2) {
        if (state == 0 && i >= n1 || state == 1 && i >= n2) {
            return 0;
        }
        
        if (memo[i][state] != -1) {
            return memo[i][state];
        }
        
        long long ans = 0;
        
        if (state == 0) {
            ans = max(ans, (nums1[i] + dp(i + 1, state, n1, n2)));
            if (um2.count(nums1[i])) {
                long long idx_nums2 = um2[nums1[i]];
                ans = max(ans, (nums1[i] + dp(idx_nums2 + 1, 1 - state, n1, n2)));
            }
        } 
        else {
            ans = max(ans, (nums2[i] + dp(i + 1, state, n1, n2)));
            if (um1.count(nums2[i])) {
                long long idx_nums1 = um1[nums2[i]];
                ans = max(ans, (nums2[i] + dp(idx_nums1 + 1, 1 - state, n1, n2)));
            }
        }
        
        return memo[i][state] = ans;
    }
    
    long long maxSum(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        long long n1 = nums1.size();
        long long n2 = nums2.size();
        
        um1.clear();
        um2.clear();
        
        for (long long i = 0; i < n1; ++i) {
            um1[nums1[i]] = i;
        }
        
        for (long long i = 0; i < n2; ++i) {
            um2[nums2[i]] = i;
        }
        
        memset(memo, -1, sizeof(memo));
        long long ans1 = dp(0, 0, n1, n2);
        
        memset(memo, -1, sizeof(memo));
        long long ans2 = dp(0, 1, n1, n2);
        
        return max(ans1, ans2) % MOD;
    }
};